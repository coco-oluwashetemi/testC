#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// task three

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

// task four
/*
int main()
{
    char yesNo;
    char userName[100];
    int operation;
    int c;
    do
    {

        printf("Hello and welcome to your basic calculator!!!\nPlease tell us your name.");

        while ((c = getchar()) != '\n' && c != EOF)
        {
        };

        fgets(userName, 100, stdin);
        userName[strcspn(userName, "\n")] = '\0';
        printf("what is your first number?");
        float firstNumber;
        scanf(" %f", &firstNumber);
        printf("Now please input your second number.");
        float secondNumber;
        scanf(" %f", &secondNumber);
        do
        {
            printf("1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n Now please enter either 1 - 4 depending on which operation you want to perform.");
            scanf(" %c", &operation);
            if (isalpha(operation))
            {
                printf("Please no letters are allowed. Try again thank you!!!\n");
                operation = 0;
            }
            else
            {
                operation = operation - '0';
                switch (operation)
                {

                case 1:
                    printf("%.2f + %.2f = %.2f", firstNumber, secondNumber, firstNumber + secondNumber);
                    break;
                case 2:
                    printf("%.2f - %.2f = %.2f", firstNumber, secondNumber, firstNumber - secondNumber);
                    break;
                case 3:
                    printf("%.2f * %.2f = %.2f", firstNumber, secondNumber, firstNumber * secondNumber);
                    break;
                case 4:
                    if (secondNumber == 0)
                    {
                        printf("sorry divisions by zero are not allowed!!!\n");
                    }
                    else
                    {
                        printf("%.2f / %.2f = %.2f", firstNumber, secondNumber, firstNumber / secondNumber);
                        break;
                    }
                default:
                    printf("Sorry you didn't pick one of the valid options listed try again.\n");
                    break;
                }
            }

        } while (operation < 1 || operation > 4);
        printf("Now do you want to try again? \"y\" for yes and any other character for no ");

        scanf(" %c", &yesNo);

        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    } while (yesNo == 'y' || yesNo == 'Y');

    printf("You have pressed somethhing else that is not \"y\". Thank you for your time. You can always restart the program. Bye!!!");

    return 0;
}*/

// task 5 building a mini gradebook
/*
int main()
{
    int yesNoDigit;
    int sum = 0;
    int grades[10];
    int gradeAmount;
    float average;
    char yesNo;
    do
    {
        printf("Hello and welcome to your gradebook app.\nHow many grades would you be working with today?\n(2 - 10)\n");

        do
        {
            scanf(" %d", &gradeAmount);

            if (gradeAmount < 2)
            {
                printf("please the minimum amount of grades you can work with on this grade app is 2.\nTry again");
            }
            else if (gradeAmount > 10)
            {
                printf("please the maximum amount of grades you can work with on this grade app is 10\nTry again");
            }
        } while (gradeAmount < 2 || gradeAmount > 10);

        for (int x = 0; x < gradeAmount; x++)
        {
            printf("Enter grade %d:\n", x + 1);
            scanf(" %d", &grades[(x)]);
            printf("grade %d recieved.\n", x + 1);
        }
        int userFunction;
        do {
        do
        {
            printf("Your grades have now been recieved. Now how would you like to proceed?\n");
            printf("press 1: View your all your grades (ordered by entry)\n");
            printf("press 2: view the sum of all your grades.\n");
            printf("press 3: view the average of all your grades.\n Please select only 1 - 3\n");

            scanf("%d", &userFunction);
        } while (userFunction < 1 || userFunction > 3);

        switch (userFunction)
        {

        case 1:
            printf("Here are all your grades ordered by entry.\n");
            for (int x = 0; x < gradeAmount; x++)
            {
                printf("Grade %d is : %d\n", (x + 1), grades[x]);
            }
            break;
        case 2:
            printf("The sum of all grades  ");
            for (int x = 0; x < gradeAmount; x++)
            {
                sum = 0;
                sum += grades[x];
                if (x == gradeAmount - 1)
                {
                    printf(" %d = %d", grades[x], sum);

                }
                else
                {
                    printf(" %d +", grades[x]);
                }

            }

            break;

        case 3:
            printf("Here is the average of all scores: ");
            for (int x = 0; x < gradeAmount; x++)
            {
                sum = 0;
                sum += grades[x];

                if (x == gradeAmount - 1)
                {
                    average = sum / gradeAmount;
                    printf(" %d = %.2f", grades[x], average);

                }
                else
                {
                    printf(" %d,", grades[x]);
                }
            }

            break;

            // no need for a default because we are already checking for digits 1-3 above. so the switch won't even be activated if its not 1 - 3
        }
        do
        {

            printf(" Now do you want to input another set of grades, perform another function with the current grades or end the program?\n");
            printf("Press 1. to start again with new grades\nPress 2. to perfrom a different function with current grades.\nPress 3. to end the program. ");
            scanf(" %c", &yesNo);
            if (isalpha(yesNo))
            {
                printf("No alphabets allowed. The only values accepeted are either \"1\", \"2\" or \"3\" thank you.");
            }
            else
            {
                yesNoDigit = yesNo - '0';
                if (yesNoDigit < 1 || yesNoDigit > 3)
                {
                    printf("Please select only \"1\", \"2\" or \"3\" thank you.");
                }
            }
        } while (isalpha(yesNo) || yesNoDigit < 1 || yesNoDigit > 3);
    }while (yesNoDigit == 2);
    } while (yesNoDigit == 1);


    printf("Thank you for trying out our gradebook app. See you again!!!");
    return 0;
}
*/

// task 6 gradebook (advanced)
/*
int main()
{
    int highestNum = 0;
    int lowestNum = 1000 * 1000;
    int checker;
    char *name;
    float average = 0;
    float sum = 0;
    char userFunctionChar;
    int userFunction;
    char studentNames[10][50];
    float studentGrades[10];
    int studentAmount;
    char yesNoChar;
    int yesNo = 0;

    do
    {
        printf("Hello and welcome to your grade analyser\nHow many students are you working with today?\n");
        scanf(" %d", &studentAmount);
        for (int x = 0; x < studentAmount; x++)
        {
            if (x == studentAmount - 1)
            {
                printf("Please input student %d's name: \n", x + 1);
                int c;
                getchar();
                fgets(studentNames[x], 50, stdin);

                studentNames[x][strcspn(studentNames[x], "\n")] = '\0';

                printf("Recieved! Now please input %s's grade:", studentNames[x]);
                scanf(" %f", &studentGrades[x]);
                printf("Great. the final students details has been recieved.\n");
            }
            else
            {
                printf("Please input student %d's name: \n", x + 1);
                int c;
                getchar();
                fgets(studentNames[x], 50, stdin);

                studentNames[x][strcspn(studentNames[x], "\n")] = '\0';

                printf("Recieved! Now please input %s's grade:", studentNames[x]);
                scanf(" %f", &studentGrades[x]);
                printf("Great. Student %d's details has been recieved.\n\n", x + 1);
            }
        }
        do
        {
            printf("All students details have now been recieved. Now please choose what function to perform.\n\n");
            do
            {
                printf("press 1: View your all of your students and their grades (in order of entry)\n");
                printf("press 2: view only one student and their grade.\n");
                printf("press 3: view the sum of all students grades.\n");
                printf("Press 4: view the average of all students grades.\n");
                printf("Press 5: view which of the students has the highest score.\n");
                printf("press 6: view the student with the lowest score.\nPlease select only numbers 1 - 6\n");

                scanf(" %c", &userFunctionChar);
                if (isalpha(userFunctionChar))
                {
                    printf("Sorry no alphabets allowed. please try again. thanks.\n\n");
                }
                else
                {
                    userFunction = 0;
                    userFunction = userFunctionChar - '0';
                    if (userFunction < 1 || userFunction > 6)
                    {
                        printf("PLEASE CHOOSE BETWEEN 1 AND 6. THANKS");
                    }
                    else
                    {
                    }
                }
            } while (userFunction < 1 || userFunction > 6 || isalpha(userFunctionChar));

            switch (userFunction)
            {
            case 1:
                for (int x = 0; x < studentAmount; x++)
                {

                    printf("\nStudent %d: \n", x + 1);
                    printf("Student Name: %s\n", studentNames[x]);
                    printf("Student Grade: %.0f\n\n", studentGrades[x]);
                }
                printf("That's all the list of student details we have saved. \n");
                break;

            case 2:
                printf("\nGreat. Now which entry profile would you like to take a look at? \n");
                printf("select from 1 - 10 depending on how much students you put in.\n\n");

                int preferredEntry;

                scanf(" %d", &preferredEntry);

                printf("\nPerfect. Here is entry %d's profile.\n\n", preferredEntry);
                printf("\nStudent %d: \n", preferredEntry);
                printf("Student Name: %s\n", studentNames[preferredEntry - 1]);
                printf("Student Grade: %.0f\n\n", studentGrades[preferredEntry - 1]);

                printf("The above is the details for student %d.", preferredEntry);
                break;

            case 3:
                // for now i don't want to print all students grades to the screen
                // maybe i'll do that later i'm too lazy so the user should just manage only the sum

                for (int x = 0; x < studentAmount; x++)
                {
                    printf("Grade %.0f : %.0f", x + 1, studentGrades[x + 1]);
                    sum += studentGrades[x];
                }
                printf("The sum of all students grades are:  %.2f", sum);
                break;

            case 4:
                // same goes for the average.
                for (int x = 0; x < studentAmount; x++)
                {
                    sum += studentGrades[x];
                    average = sum / studentAmount;
                }
                printf("The average of all students grades are:  %.2f", average);
                break;

            case 5:

                for (int x = 0; x < studentAmount; x++)
                {
                    checker = studentGrades[x];
                    if (highestNum < checker)
                    {
                        highestNum = checker;
                        name = studentNames[x];
                    }
                }
                printf("The Highest grade in the class is %d. It was gotten by the student %s. Thank you\n\n", highestNum, name);
                break;
            case 6:
                for (int x = 0; x < studentAmount; x++)
                {

                    checker = studentGrades[x];

                    if (lowestNum > checker)
                    {
                        lowestNum = checker;
                        name = studentNames[x];
                    }
                }
                printf("The lowest grade in the class is %d. It was gotten by the student %s. Thank you\n\n", lowestNum, name);
                break;
            }

            do
            {

                printf("\nGreat. Now how would you like to proceed? Please choose of the following 3.");
                printf("Press 1. to start again with new grades\nPress 2. to perfrom a different function with current grades.\nPress 3. to end the program. ");
                scanf(" %c", &yesNoChar);
                if (!isdigit(yesNoChar))
                {
                    printf("Please you are only allowed to input in digits 1 - 3. Try again.");
                }
                else
                {
                    yesNo = yesNoChar - '0';
                }
            } while (yesNo < 1 || yesNo > 3);
        } while (yesNo == 2);
    } while (yesNo == 1);

    printf("Thank you for trying our Advanced grade ananlyzer. Have a lovely day come back whenever you can!");
    return 0;
}
*/