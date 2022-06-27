#include "main.h"

void login()
{
    int pass;

    printf("\n\n\n\n\n\n\t\t\t\t\t\t   WELCOME TO THE INVENTORY MANAGEMENT LOGIN SYSTEM");

    printf("\n\n\n\t\t\t\t\t\t\t     Enter Admin Password: ");                               /// Password Required is 92125

    scanf("%d", &pass);

    if (pass == 92125)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tADMIN LOGIN APPROVED!");
        menu(); /*The Main Menu function will be called*/
    }
    else
    {
        while (pass != 92125)                                                               /// This part will repeat the following if password entered is not 92125
        {
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t   Invalid Input! Please Try Again!");

            printf("\n\n\n\t\t\t\t\t\t\t     Enter Admin Password: ");                      /// Password Required is 92125

            scanf("%d", &pass);

            if (pass == 92125)
            {
                printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tADMIN LOGIN APPROVED!");
                menu();                                                                     /// This is the condition to break out of the loop by entering the correct password after one or more wrong attempts
            }
        }
    }
}