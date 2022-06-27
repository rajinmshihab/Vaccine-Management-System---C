#include "main.h"

void newrec()
{
    struct vaccine
    {
        int dosrec;             /// Dosage Required
        char nov[19];           /// Vaccine Name
        char vcode[3];          /// Vaccine Code
        char procon[11];        /// Producing Country
        double popcov;          /// Population Covered
        double quan;            /// Quantity Stored [ Real-Time ]
        double disq;            /// Distributed Quantity
        double newquan;         /// New Quantity
    }v;

    FILE* vacrec;
    int i, j, choice;

    printf("\n\n\n\t\t\t\t\t\t\tWelcome To Inventory Creation Section");

    printf("\n\n\nKeep Previous Records? [ Enter <1> To Keep and <0> To Start Anew ]: ");
    scanf("%d", &choice);

    while (choice != 1 && choice != 0)
    {
        printf("\nInvalid Operation! Please Try Again: ");
        scanf("%d", &choice);
    }
    if (choice == 0 || choice == 1)
    {
        if (choice == 0)
        {
            vacrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt", "w");           /// REPLACE current file
        }

        else if (choice == 1)
        {
            vacrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt", "a");           /// APPREND to current file
        }
    }

    printf("\n\n\nHow Many New Records Would You Like To Add?: ");
    scanf("%d", &j);

    if (vacrec == NULL)
    {
        printf("File Not Found");
    }
    else
    {
        for (i = 0; i < j; i++)
        {
            printf("\n\n\t\t\t\t\t\t\t  Records Creation Section!!!\n\n\t\t\t\t\t\t\t\t***Reminder***\n\t\t\t\t\t\t\t    Use '_' instead of 'SPACE'");
            
            printf("\n\n\n\nEnter Vaccine Name: ");
            scanf("%s", &v.nov); ///This is a dummy scanf() function used for tackling the problem of scanf() skipping lines. Only one input will be taken from user.

            printf("\nEnter Vaccine Code: ");
            scanf("%s", &v.vcode);

            printf("\nEnter Vaccine Country of Production: ");
            scanf("%s", &v.procon);

            printf("\nEnter Dosage Required: ");
            scanf("%d", &v.dosrec);

            printf("\nEnter Population Covered [ Percentage ]: ");
            scanf("%lf", &v.popcov);

            printf("\nEnter Initial Quantity [ Millions ]: ");
            scanf("%lf", &v.quan);

            fprintf(vacrec, "%-15s %-16s %-22s %-23d %-23.2f %.2f\n", v.nov, v.vcode, v.procon, v.dosrec, v.popcov, v.quan); /* Writing The Details Into [ vaccine.txt ] */
        }
    }

    fclose(vacrec);
    printf("\n\n\n\t\t\t\t\t\t\t\t   Redirecting to Menu!");
    menu(); /* Recall The menu() Function */

}