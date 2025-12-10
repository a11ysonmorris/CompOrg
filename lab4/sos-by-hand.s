.section .rodata # Begin read-only data segment
.align 32 # Address of following label will be a multiple of 32
.fmt: # Label of SOS format string
.string "sos(%i,%i)=%i\n" # SOS format string
.text # Begin text segment (where code is stored)
.align 4 # Address of following label will be a multiple of 4
sq: # Label for sq() function
pushl %ebp # \ Standard callee entrance
movl %esp, %ebp # /
movl 8(%ebp), %eax # result <- x
imull 8(%ebp), %eax # result <- x*result
leave # \ Standard callee exit
ret # /
.align 4 # Address of following label will be a multiple of 4
sos: # Label for sos() function
pushl %ebp # \ Standard callee entrance
movl %esp, %ebp # /
pushl 8(%ebp) # push y as arg to sq()
call sq # %eax <- sq(y)
movl %eax, %ebx # save sq(y) in %ebx
addl $4, %esp # pop y off stack (not really necessary)
pushl 12(%ebp) # push z as arg to sq()
call sq # %eax <- sq(z)
addl $4, %esp # pop z off stack (not really necessary)
addl %ebx, %eax # %eax <- %eax + %ebx
leave # \ Standard callee exit
ret # /
.align 4 # Address of following label will be a multiple of 4
.globl main # Main entry point is visible to outside world
main: # Label for main() function
pushl %ebp # \ Standard callee entrance
movl %esp, %ebp # /
# int a = atoi(argv[1])
subl $8, %esp # Allocate space for local variables a and b
movl 12(%ebp), %eax # %eax <- argv pointer
addl $4, %eax # %eax <- pointer to argv[1]
pushl (%eax) # push string pointer in argv[1] as arg to atoi()
call atoi # %eax <- atoi(argv[1])
movl %eax, -4(%ebp) # a <- %eax
addl $4, %esp # pop arg to atoi off stack
# int b = atoi(argv[2])
movl 12(%ebp), %eax # %eax <- argv pointer
addl $8, %eax # %eax <- pointer to argv[2]
pushl (%eax) # push string pointer in argv[2] as arg to atoi()
call atoi # %eax <- atoi(argv[2])
movl %eax, -8(%ebp) # b <- %eax
addl $4, %esp # pop arg to atoi off stack
# printf("sos(%i,%i)=%d\n", a, b, sos(a,b))#
# First calculate sos(a,b) and push it on stack
pushl -8(%ebp) # push b
pushl -4(%ebp) # push a
call sos # %eax <- sos(a,b)
addl $8, %esp # pop args to sos off stack
pushl %eax # push sos(a,b)
# Push remaining args to printf
pushl -8(%ebp) # push b
pushl -4(%ebp) # push a
pushl $.fmt # push format string for printf
# Now call printf
call printf
addl $16, %esp # pop args to printf off stack (not really necessary)
leave # \ Standard callee exit
ret # /
