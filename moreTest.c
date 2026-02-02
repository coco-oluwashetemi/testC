#include <stdio.h>

int main()
{
    int userInput[4];
    int swap = 0;
    for (int i = 0; i < 4; i++)
    {
       
        printf("\nenter number %d\n", (i + 1));
        scanf("%d", &userInput[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("\nHere");
        printf("%d\n", userInput[i]);
    }
    swap=userInput[0];
    userInput[0]=userInput[1];
    userInput[1] = swap;
    swap=userInput[2];
    userInput[2]=userInput[3];
    userInput[3] = swap;
     for (int i = 0; i < 4; i++)
    {
        printf("\nHere");
        printf("%d\n", userInput[i]);
    }

    return 0;
}