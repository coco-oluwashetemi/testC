#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedListFunctions.h"

void greeting_menu(int *userChoice)
{
    printf("\n1.    Add a book/books\n2.    Display a book\n3.    Display all books\n4.    Deltet a book");
    printf("\n5.    Exit the program\n");

    while (true)
    {

        scanf(" %d", userChoice);
        getchar();

        if ((*userChoice) >= 1 && (*userChoice <= 5))
        {
            break;
        }
        printf("Please enter a number between (1 - 5). Try Again.");
    }
}/*











*/

// function to add a new node
void addNode(List **head)
{
    // Allocate memory for a new node
    List *newNode = malloc(sizeof(List));

    // Get book title
    printf("Please enter the book title \n");
    fgets(newNode->book.title, 50, stdin);
    newNode->book.title[strcspn(newNode->book.title, "\n")] = 0; // Remove newline

    // Get book author
    printf("Please enter the author of this book \n");
    fgets(newNode->book.author, 50, stdin);
    newNode->book.author[strcspn(newNode->book.author, "\n")] = 0; // Remove newline

    // Get book price
    printf("How much does this book cost? ");
    scanf(" %f", &newNode->book.price);
    getchar(); // consume leftover newline

    newNode->next = NULL; // New node will be the last node

    // If list is empty, new node becomes head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Otherwise, traverse to the end of the list
        List *currentVoid;
        currentVoid = *head;
        while (currentVoid->next != NULL)
        {
            currentVoid = currentVoid->next;
        }

        // Attach new node at the end
        currentVoid->next = newNode;
    }
}/*













*/

// function to print all values in each node
void printBooks(List *head)
{
    // Traverse the list and print each book's details
    List *current = head;
    int count = 1;
    if (head == NULL)
    {
        printf("\nNo books to display.\n");
        return;
    }
    while (current != NULL)
    {
        printf("\nDetails of Book %d\n", count);
        printf("title:  %s\n", current->book.title);
        printf("author:  %s\n", current->book.author);
        printf("price:  %.2f\n", current->book.price);

        count++;
        current = current->next; // Move to next node
    }
    printf("\nAll books printed successfully");
}
/*











*/

void searchFor(List *head)
{
    List *current = head;
    printf("\nPlease, enter the title of the book you are looking for : ");
    char *BookToBeFound = malloc(50 * sizeof(char));
    if (BookToBeFound == NULL)
    {
        printf("Malloc did not work");
    }
    fgets(BookToBeFound, 50, stdin);
    BookToBeFound[strcspn(BookToBeFound, "\n")] = 0;

    int count = 0;

    while (current != NULL)
    {
        if (strcmp(BookToBeFound, current->book.title) == 0)
        {
            printf("\nDetails of Book :\n");
            printf("title:  %s\n", current->book.title);
            printf("author:  %s\n", current->book.author);
            printf("price:  %.2f\n", current->book.price);
            count++;
        }

        current = current->next; // Move to next node
    }

    printf("\n%d Books have been found with the titles matching \"%s\"", count, BookToBeFound);
    free(BookToBeFound);
} /*

















 */

void deleteNode(List **head)
{
    List *current = *head;
    List *previous = NULL;
    printf("\nPlease, enter the title of the book you are looking to delete: ");
    char *BookToBeDeleted = malloc(50 * sizeof(char));
    if (BookToBeDeleted == NULL)
    {
        printf("Malloc did not work");
    }
    fgets(BookToBeDeleted, 50, stdin);
    BookToBeDeleted[strcspn(BookToBeDeleted, "\n")] = 0;
    bool check = false;
    while (current != NULL)
    {
        if (strcmp(BookToBeDeleted, current->book.title) == 0)
        {
            check = true;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (check == true)
    {
        if (current == *head)
        {
            *head = (*head)->next;
            free(current);
            printf("Book titled : %s, has been successfully deleted!!!", BookToBeDeleted);
        }
        else
        {
            previous->next = current->next;
            free(current);
            printf("Book titled : %s, has been successfully deleted!!!", BookToBeDeleted);
        }
    }
    else
    {
        printf("There was no book titled \"%s\"", BookToBeDeleted);
    }

    free(BookToBeDeleted);
} /*












 */

void freeNodes(List **head)
{
    List *current = *head;
    List *prev = current;
    while (current != NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *head = NULL;
}
/*




















*/
void insertBook(List **head)
{
    List *current = *head;
    int count = 0; // this is used to count how many books we already have

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    // this is a check to see if we have any books even before creating anything
    if (count == 0)
    {
        printf("\nyou currently have no books available. Enter book details below to start adding to your list of books. ");
    }

    // if we have have books, then we can create a new node
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL)
    {
        printf("malloc failed");
        return;
    }

    // Get book title
    printf("Please enter the book title \n");
    fgets(newNode->book.title, 50, stdin);
    newNode->book.title[strcspn(newNode->book.title, "\n")] = 0; // Remove newline

    // Get book author
    printf("Please enter the author of this book \n");
    fgets(newNode->book.author, 50, stdin);

    newNode->book.author[strcspn(newNode->book.author, "\n")] = 0; // Remove newline

    // Get book price
    printf("How much does this book cost? ");
    scanf(" %f", &newNode->book.price);
    getchar(); // consume leftover newline

    newNode->next = NULL; // New node will be the last node

    int indexForBook = 1;

    if (count > 0)
    {

        printf("\nAt what position would you like to have your new Book?");
        printf("\n\nFor reference, you have a total of %d book(s). ", count);
        printf("\ni.e : if you enter : 1 then details in the current book becomes the first book and previous first book is now second. )");
        printf("\nNote : 1 inserts it at the head, and 1 digit above list total (%d) inserts it at the end.\n", count);
        printf("\nFinally, if selecting the last book i.e: %d, book is added as the second last i.e: just before the last\n", count);

        // we have a check for where the book is supposed to be
        do
        {
            printf("\n\nPlease pick between 1 and %d\n", count + 1);
            scanf(" %d", &indexForBook);
            getchar();
        } while (indexForBook < 1 || indexForBook > count + 1);

        printf("\nPerfect. \n");
    }
    if (indexForBook == 1)
    {
        current = *head;
        *head = newNode;
        (*head)->next = current;
    }
    else if (indexForBook == count + 1)
    {
        current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    else
    {
        current = *head;
        for (int i = 1; i < indexForBook - 1; i++)
        {
            current = current->next;
        }
        List *temp = current->next;
        current->next = newNode;
        newNode->next = temp;
    }

    printf("\nAdded successfully!!!");
} /*













 */

void reverseBooks(List **head)
{
    List *current = *head;
    List *prev = NULL;
    List *temp = NULL;
    int count = 0;
    int booksListAmount = 0;

    while (current != NULL)
    {
        booksListAmount++;
        current = current -> next; 
       
    }
    current = *head; 

    if (booksListAmount == 0)
    {
        printf("\nNo list present to be reversed!!!\n");
        return;
    }

    else if (booksListAmount == 1)
    {
        printf("\nreversed successfully");
        return;
    }
    else if (booksListAmount == 2)
    {
        
        List *current = *head;
        List *temp = current;

        current = current->next; 
        current -> next = temp; 
        temp->next = NULL; 
        *head = current;  
        return; 

    }
    else if (booksListAmount >= 3)
    {
        while (current->next != NULL)
        {

            while (current->next != NULL)
            {
                prev = current;
                current = current->next;
            }

            current->next = prev;
            prev->next = NULL;
            count++;
            if (count == 1)
            {
                temp = current;
            }
            current = *head;
        }

        *head = temp;
        printf("\nBook list has been reversed successfully!!!\n");
        return; 
    }
}
void reverseBooks(List **head)
{
    List *current = *head;
    List *prev = NULL;
    List *temp = NULL;
    
    
}