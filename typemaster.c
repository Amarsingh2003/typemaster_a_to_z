// program to check the typing speed to write (a to z )
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void check_error_in_typing(char s[]) // in this function we just print no of error and the error's alphabet
{
    int length_of_string = strlen(s) - 1;
    int i = 0;
    char j = 97; // we take ascii value of 'a'
    int count = 0; // its count error
    float accuracy;
    while (i < length_of_string && j <= 122)
    {

        if (s[i] != j)
        {

            printf("\033[31m%c: \033[0m", s[i]);
            count++;
        }
        i++;
        j++;
    }
    printf("\t\033[34m no of error in writting \033[0m \033[31m%d\033[0m", count);
    accuracy=((length_of_string-count)*100)/26;

    printf("\n \033[31maccuracy %.2f \033[0m",accuracy);
}

int main()
{
    char choice;
    char name[50];
    char repeat;    //printf("\033[31mThis is red font.\033[0m\n"); this print output text in red color
    do
    {
        printf("\t\033[31m--------        welcome to test your typing          -----------\033[0m\n");
        printf("\033[34menter your choice\033[0m\n");
        printf("\033[33mpress \033[32m's'\033[0m \033[33mto start and \033[32m'e'\033[0m \033[33mto exit\033[0m \t");
        scanf("%c", &choice);
        fflush(stdin);
        if (choice == 's')
        {

            char s[100];

            printf("\033[34m----   Enter your name\033[0m \t ");
            int count = 0;
            gets(name);

            printf("\033[33mhii %s \033[0m\n", name);
            Sleep(2000);
            printf("\033[34mIn this test you have to write the english alphebets from (A-Z)\033[0m\n");
            Sleep(3000);
            printf("\033[33m------  write the alphabet (A-Z) !\033[0m\t");
            Sleep(200);
            float length;
            length = strlen(s) - 1;
            time_t start, end;  // this instruction is used to calculate the time period
            start = time(NULL);

            fgets(s, 100, stdin);
            end = time(NULL);
            printf("\033[33mTime taken to print (a-z) is\033[0m \033[32m %.2f seconds\033[0m\n", difftime(end, start));
            fflush(stdin);

            check_error_in_typing(s);

            printf("\n\033[31mThe letter per second (L.P.S) %.2f\033[0m", length / difftime(end, start));
            Sleep(2000);
            printf("\n\033[34mdo you want to type again then press \033[0m\033[33m'y'\033[0m otherwise press any key\t");
            scanf("%c", &repeat);
            fflush(stdin);
        }
        else
        {
            printf("\033[32mthank you for visiting \033[0m\n");
        }
    } while (repeat == 'y');

    return 0;
}