/*
 * lab1p4.c
 * CSCI 304 - Fall 2025
 *
 * Author: Krishna Swaminathan and Allyson Morris
 * Description:
 *   Implements a linked list where:
 *     - Words starting with uppercase letters go to the beginning.
 *     - Words starting with lowercase letters go to the end.
 *     - If a word already exists, it is deleted before reinserting.
 *   Provides insert, delete, find, and display functions.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 
 // Node structure
 struct Node {
     char *data;
     struct Node *next;
 };
 
 // Linked list structure
 struct Linkedlist {
     struct Node *head;
 };
 
 // Function prototypes
 void insertAtBeginning(struct Linkedlist *LL, char ele[]);
 void insertAtTheEnd(struct Linkedlist *LL, char ele[]);
 void deleteNode(struct Linkedlist *LL, char ele[]);
 int findNode(struct Linkedlist LL, char ele[]);
 void displayLinkedList(struct Linkedlist LL);
 
 int main(int argc, char *argv[]) {
     if (argc < 2) {
         printf("ERROR: The program must read at least an argument.\n");
         return 1;
     }
 
     struct Linkedlist LL;
     LL.head = NULL;
 
     for (int i = 1; i < argc; i++) {
         char *word = argv[i];
 
         // If exists, delete it before reinserting
         if (findNode(LL, word)) {
             deleteNode(&LL, word);
         }
 
         // Insert based on first character
         if (isupper(word[0])) {
             insertAtBeginning(&LL, word);
         } else if (islower(word[0])) {
             insertAtTheEnd(&LL, word);
         }
     }
 
     printf("The list:- ");
     displayLinkedList(LL);
 
     return 0;
 }
 
 // Insert at beginning
 void insertAtBeginning(struct Linkedlist *LL, char ele[]) {
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     if (!newNode) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(1);
     }
     newNode->data = (char *)malloc(strlen(ele) + 1);
     strcpy(newNode->data, ele);
 
     newNode->next = LL->head;
     LL->head = newNode;
 }
 
 // Insert at end
 void insertAtTheEnd(struct Linkedlist *LL, char ele[]) {
     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
     if (!newNode) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(1);
     }
     newNode->data = (char *)malloc(strlen(ele) + 1);
     strcpy(newNode->data, ele);
     newNode->next = NULL;
 
     if (LL->head == NULL) {
         LL->head = newNode;
     } else {
         struct Node *temp = LL->head;
         while (temp->next != NULL) {
             temp = temp->next;
         }
         temp->next = newNode;
     }
 }
 
 // Delete a node by value
 void deleteNode(struct Linkedlist *LL, char ele[]) {
     struct Node *temp = LL->head;
     struct Node *prev = NULL;
 
     while (temp != NULL) {
         if (strcmp(temp->data, ele) == 0) {
             if (prev == NULL) {
                 // Deleting head
                 LL->head = temp->next;
             } else {
                 prev->next = temp->next;
             }
             free(temp->data);
             free(temp);
             return;
         }
         prev = temp;
         temp = temp->next;
     }
 }
 
 // Find a node by value
 int findNode(struct Linkedlist LL, char ele[]) {
     struct Node *temp = LL.head;
     while (temp != NULL) {
         if (strcmp(temp->data, ele) == 0) {
             return 1;
         }
         temp = temp->next;
     }
     return 0;
 }
 
 // Display the linked list
 void displayLinkedList(struct Linkedlist LL) {
     struct Node *temp = LL.head;
     while (temp != NULL) {
         printf("%s", temp->data);
         if (temp->next != NULL) {
             printf(", ");
         }
         temp = temp->next;
     }
     printf("\n");
 }
 
