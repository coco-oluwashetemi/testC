#include "linkedListFunctions.c"

int main()
{
    List *head = NULL;
    int booksAmount;
    int userChoice;

    printf("\nHello and welcome to your Book Storage unit. \n");
    printf("\nNow that we have you here, which of the following functions would you like to perform? \n");
    

    do
    {
        greeting_menu(&userChoice);

        if (userChoice == 1)
        {
            printf("How many books would you like to add? ");
            scanf(" %d", &booksAmount);
            getchar();
            for (int i = 1; i <= booksAmount; i++)
            {
                printf("\nBook %d:", i);
                addNode(&head);
            }
            printf("\nBook/s added Successfully\n");
            printf("\nAnything else you would like to do? \n");
        }

        else if (userChoice == 2)
        {
            searchFor(head);
            printf("\nAnything else you would like to do? \n");
        }
        else if (userChoice == 3)
        {
            printBooks(head);
            printf("\nAnything else you would like to do? \n");
        }
        else if (userChoice == 4)
        {
            deleteNode(&head);
            printf("\nAnything else you would like to do? \n");
        }
        else if (userChoice == 5)
        {
            printf("Thank you for using our system. We hope to see you again soo. BYE!!!");
        }


    } while (userChoice != 5);



    
    freeNodes(&head); //once done with the whole program, we call the free node function that clears all the allocated memory

    printf("\nThank you for using our program!!!");


    return 0;
}
