#include "main.h"

void disInvRec()
{
    char str[120];
    
    FILE *vacrec;
    vacrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt", "r");

    if (vacrec == NULL)
    {
        printf("\n\nFIle Missing!!!");
        menu();
    }

    printf("\nVaccine Name\tVaccine code\t Producing Country\tDosage Required \tPopulation Covered \tQuantity \n\n");

    while ((fgets(str, 120, vacrec)) != NULL)
    {
        printf("%s",str);
    }

    fclose(vacrec);
    printf("\n\n\n\t\t\t\t\t\t\tPress Enter To Redirect Back To The Menu");
    getchar(); /// Dummy getchar() to solve the problem of getchar() skipping lines
    getchar();
    menu();
}