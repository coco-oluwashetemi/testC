#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// practicing structs

typedef struct
{
    char title[50];
    char author[50];
    float price;
} Book;

typedef struct List
{
    Book book;
    struct List *next;
} List;

void addNode();

int main()
{
    List *current;
    List *head = NULL;


    printf("Welcome. How many books would  you like to work with today? \n");
    int booksAmount;
    scanf(" %d", &booksAmount);
    getchar(); // to consume the newline character after scanf

    if (booksAmount <= 0)
    {
        printf("The amount you entered is equal to or lower than the required. Please restart the program to try again. ");
    }
    else{
        for (int i = 1; i <= booksAmount; i++)
        {
            printf("\nFor book %d: \n", i); 
            addNode(&head); 
        }
        
        
    }

    current = head;
    int count = 1;
    while (current != NULL)
    {
        List *temp = current;
        printf("\nDetails of Book %d\n", count);
        printf("title:  %s\n", current->book.title);
        printf("author:  %s\n", current->book.author);
        printf("price:  %.2f\n", current->book.price);

        count++;
        current = current->next;
        free(temp);
    }

    printf("\nThank you for using our program!!!");
    return 0;
}

void addNode(List **head)
{
    List *newNode = malloc(sizeof(List));
    printf("Please enter the book title \n");
    fgets(newNode->book.title, 50, stdin);
    newNode->book.title[strcspn(newNode->book.title, "\n")] = 0;
    printf("Please enter the author of this book %d\n", 1);
    fgets(newNode->book.author, 50, stdin);
    newNode->book.author[strcspn(newNode->book.author, "\n")] = 0;
    printf("How much does this book cost? ");
    scanf(" %f", &newNode->book.price);
    getchar(); // to consume the newline character after scanf

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        List *currentVoid;
        currentVoid = *head;
        while (currentVoid -> next !=  NULL)
        {
            currentVoid = currentVoid->next;
        }
        
        currentVoid -> next = newNode; 
    }
}