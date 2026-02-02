#include <stdio.h>
#include <string.h>
// task one
/* int main()
{
    printf("Hello,World!");

    return 0;
}
#include <stdio.h>

int main(){
    printf("Hello world");
    return 0 ;
}
*/

// task two

/*int main (){
    char userName[50];
    int userAge;
    printf("Hello! please let us know what your name is. Preferably your full name.\n");
    scanf(" %[^\n]", userName);
    printf("perfect!!! Now can you tell us your age." );
    scanf("%d", &userAge);
    printf("Hello %s, you are %d years old!!!\n", userName, userAge);

    return 0;
}
*/

//task three

/*
int main()
{
    char yesNo;
    do
    {

        printf("Hello and welcome to your basic calculator!!!\nPlease tell us your name.");
        char userName[100];
        fgets(userName, 100, stdin);
        userName[strcspn(userName, "\n")] = '\0';
        printf("what is your first number?");
        float firstNumber;
        scanf(" %f", &firstNumber);
        printf("Now please input your second number.");
        float secondNumber;
        scanf(" %f", &secondNumber);
        float sum = firstNumber + secondNumber;
        printf("Thank you\nThe sum of %.0f and %.0f is %.0f\n", firstNumber, secondNumber, sum);

        printf("Now do you want to try again? \"y\" for yes and any other character for no ");

        scanf(" %c", &yesNo);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    } while (yesNo == 'y' || yesNo == 'Y');

    printf("You have pressed somethhing else that is not \"y\". Thank you for your time. You can always restart the program. Bye!!!");

    return 0;
}
*/

//task four

int main()
{
    char yesNo;
    char userName[100];
    int operation ;
    do
    {

        printf("Hello and welcome to your basic calculator!!!\nPlease tell us your name.");
        
        int c;
        while ((c = getChar()) != '\n' && c != EOF){};

        fgets(userName, 100, stdin);
        userName[strcspn(userName, "\n")] = '\0';
        printf("what is your first number?");
        float firstNumber;
        scanf(" %f", &firstNumber);
        printf("Now please input your second number.");
        float secondNumber;
        scanf(" %f", &secondNumber);
        printf("1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n Now please enter either 1 - 4 depending on which operation you want to perform.");
        scanf(" %d", &operation);
        //the error is that printf is not getting seen, or its parameters is not getting detected
        //might be a visual studio code thing
        //currently printf is taking in only one argument, and the argument has an error type.
        switch(operation){
            case 1 : 
                printf("%f + %f");
                break;
        }

        printf("Now do you want to try again? \"y\" for yes and any other character for no ");

        scanf(" %c", &yesNo);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    } while (yesNo == 'y' || yesNo == 'Y');

    printf("You have pressed somethhing else that is not \"y\". Thank you for your time. You can always restart the program. Bye!!!");

    return 0;
}