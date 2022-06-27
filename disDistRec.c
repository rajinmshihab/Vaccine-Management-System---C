#include "main.h"

void disDistRec()
{
    FILE* distrec;

    char str[120];
    
    distrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/dist.txt","r");

    if (distrec == NULL)
    {
        printf("\n\nFIle Missing!!!");
        menu();
    }

    printf("\nVaccine Code\tDistributed Quantity [Millions] \n\n");

    while ((fgets(str, 120, distrec)) != NULL)
    {
        printf("%s",str);
    }

    fclose(distrec);                                            /// Close FIle

    printf("\n\n\n\t\t\t\t\t\t\tPress Enter To Redirect Back To The Menu");
    getchar(); /// Dummy getchar() to solve the problem of getchar() skipping lines
    getchar();
    menu();
}