#include "main.h"

void menu()
{
    int choice;

    printf("\n\n\n\t\t\t\t\t\t\t\t\tMain Menu");
    printf("\n\n\nAvailable Functions\n\n\n1. Inventory Creation / Create New Inventory  \n\n2. Update Inventory & List Of Distribution  \n\n3. Search For Inventory Entry [ Via Vaccine Code ]    \n\n4. Display Current Inventory    \n\n5. Display Distribution List    \n\n6. Exit");
    printf("\n\n\n\nEnter Your Choice [ Use Numbers Between (1 - 6) ]: ");

    scanf("%d", &choice);
    
    while (choice < 1 || choice > 6)
    {
        printf("\nInvalid Operation! Please Try Again: ");
        scanf("%d", &choice);
    }

    if (choice > 0 && choice <7)
    {
        if (choice == 1) /* Call Function For Inventory Creation / Create New Inventory */
        {
            newrec();
        }

        else if (choice == 2) /* Call Function To Update Inventory & List Of Distribution */
        {
            uprec();
        }

        else if (choice == 3) /* Call Function To Search For Inventory Entry [ Via Vaccine Code ] */
        {
            searchrec();
        }

        else if (choice == 4) /* Call Function To Display Current Inventory */
        {
            disInvRec();
        }

        else if (choice == 5) /* Call Function To Display Distribution List */
        {
            disDistRec();
        }

        else if (choice == 6) /* Exit */
        {
            printf("\n\n\n\t\t\t\t\t\t\t\t\tGood Bye!");
        }
    }
}