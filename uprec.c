#include "main.h"

void uprec()
{
    FILE* distrec;
    FILE* vacrec;
    FILE* temprec;

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

    char pos;
    char scode[3];
    char str[120];
    int flag = 0;

    printf("\n\n\nEnter The Vaccine Code [ Case Sensitive. Capitals Only ]: ");
    scanf("%s", &scode);

    /// distrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/dist.txt","w");
    distrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/dist.txt","a");
    vacrec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt","r+");

    while ((fgets(str, 120, vacrec)) != NULL)                                /// Search For Code in vaccine.txt
    {
        pos = strstr(str, scode);
        if (pos != NULL)
        {
            flag = flag + 1 ;
            break;
        }
    }

    if (flag == 0)                                                          /// Divert Flows For Code Being Found or Not Found
    {
        printf("\nNo Entry Found For Vaccine Code '%s' !!!", scode);
    }
    else                                                                    /// Change Records of vaccine.txt
    {
        printf("\n\n\nEnter Distributed Quantity [ MILLIONS ]: ");
        scanf("%lf", &v.disq);

        if (v.disq > 0)
        {
            temprec = fopen("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/temp.txt","w");
            rewind(vacrec);
            while (fscanf(vacrec, "%s %s %s %d %lf %lf", v.nov, v.vcode, v.procon, &v.dosrec, &v.popcov, &v.quan) != EOF)
            {
                if (strcmp(v.vcode, scode) == 0)
                {
                    v.newquan = v.quan - v.disq;
                    fprintf(temprec,"%-15s %-16s %-22s %-23d %-23.2f %.2f\n", v.nov, v.vcode, v.procon, v.dosrec, v.popcov, v.newquan);
                }
                else
                {
                    fprintf(temprec,"%-15s %-16s %-22s %-23d %-23.2f %.2f\n", v.nov, v.vcode, v.procon, v.dosrec, v.popcov, v.quan);
                }
            }

            fprintf(distrec,"%-16s%.2f\n", scode, v.disq);
            fclose(distrec);
            fclose(vacrec);
            fclose(temprec);

            remove("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt");
            rename("D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/temp.txt","D:/University/Semester - 2/032021 - SVG - ICP/VsCode Programs/Assignment_Project/vaccine.txt");
            printf("\n\n\n\t\t\t\t\t\t\tPress Enter To Redirect Back To The Menu");
            getchar();                                                              /// Dummy getchar() to solve the problem of getchar() skipping lines
            getchar();
            menu();
        }
        else
        {
            printf("\n\n\n\t\t\t\t\t\t\tInvalid Records Entered! Terminating Program!");
        }
    }
}