#include "main.h"

void searchrec()
{
    FILE *vacrec;

    char scode[3];
    char pos;
    char str[120];
    int col, count;
    int flag = 0;

    printf("\n\n\n\t\t\t\t\t\t\t     tWelcome To The Search Section!!!");
    printf("\n\n\nEnter The Vaccine Code [ Case Sensitive. Capitals Only ]: ");
    scanf("%s",scode);

    vacrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt","r");

    
    if (vacrec == NULL)
    {
        printf("\n\n\t\t\t\t\t\t\t\tCannot Open File!!! Redirecting To Menu!!!\n");
        menu();                                                     /// Exit To Menu
    }

    while ((fgets(str, 120, vacrec)) != NULL)
    {
        pos = strstr(str, scode);                                   /// Finding The First Occurance Of Given Code

        if (pos != NULL)
        {
            printf("\n\nVaccine Name\tVaccine code\t Producing Country\tDosage Required \tPopulation Covered \tQuantity \n\n");
            printf("%s", str);
            flag = flag + 1 ;
            break;
        }
    }

    if (flag == 0)
    {   
        printf("\nNo Entry Found For Vaccine Code '%s' !!!", scode);
    }
    
    fclose(vacrec);
    printf("\n\n\n\t\t\t\t\t\t\tPress Enter To Redirect Back To The Menu");
    getchar();                                                      /// Dummy getchar() to solve the problem of getchar() skipping lines
    getchar();
    menu();
}