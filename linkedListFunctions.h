#ifndef linkedListFunctions_H
#define linkedListFunctions_H


// practicing structs

// Struct representing a book with title, author, and price
typedef struct
{
    char title[50];
    char author[50];
    float price;
} Book;

// Node structure for a singly linked list
typedef struct List
{
    Book book;
    struct List *next;
} List;

// my functions predefined
void greeting_menu(int *userChoice);
void addNode(List **head);
void searchFor(List *head);
void printBooks(List *head);
void deleteNode(List **head);
void freeNodes(List **head);
void insertBook(List **head);
void reverseBooks(List **head);

#endif