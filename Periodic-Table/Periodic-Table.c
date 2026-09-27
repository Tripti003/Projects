#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "elements.h"

int i;

/* Function declarations */
void Modern_periodic_table(void);
void search(void);
void info1(void);
void info2(void);
void info3(void);
void info4(void);
void quit(void);
void again(void);


/* =========================
   PERIODIC TABLE DISPLAY
   ========================= */

void Modern_periodic_table(void)
{
    printf("\n");
    printf("                    MODERN PERIODIC TABLE\n\n");

    printf("       1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18\n");

    printf("  1    H                                                                  He\n");

    printf("  2    Li  Be                                          B   C   N   O   F   Ne\n");

    printf("  3    Na  Mg                                          Al  Si  P   S   Cl  Ar\n");

    printf("  4    K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr\n");

    printf("  5    Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe\n");

    printf("  6    Cs  Ba  La* Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn\n");

    printf("  7    Fr  Ra  Ac** Rf  Db  Sg  Bh  Hs  Mt  Ds  Rg  Cn  Nh  Fl  Mc  Lv  Ts  Og\n");

    printf("\n");

    printf("             *  La  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu\n");

    printf("            **  Ac  Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm  Md  No  Lr\n");

    printf("\n\n");
}


/* =========================
   QUIT
   ========================= */

void quit(void)
{
    char ans[5];

    printf("\n");
    printf("\033[31mARE YOU SURE YOU WANT TO QUIT? [Y/N]: \033[0m");
    scanf("%4s", ans);

    if (tolower((unsigned char)ans[0]) == 'y')
    {
        printf("\n\n\033[35mTHANK YOU\033[0m\n\n");
        exit(0);
    }

    if (tolower((unsigned char)ans[0]) == 'n')
    {
        return;
    }

    printf("\n\033[31mINVALID INPUT!\033[0m\n");
}


/* =========================
   ASK FOR ANOTHER SEARCH
   ========================= */

void again(void)
{
    char ans[5];

    printf("\n\n");
    printf("\033[32mSEARCH FOR A DIFFERENT ELEMENT? [Y/N]: \033[0m");
    scanf("%4s", ans);

    if (tolower((unsigned char)ans[0]) == 'y')
    {
        search();
    }
    else if (tolower((unsigned char)ans[0]) == 'n')
    {
        quit();
    }
    else
    {
        printf("\033[31mINVALID INPUT!\033[0m\n");
        again();
    }
}


/* =========================
   SEARCH BY ELEMENT NAME
   ========================= */
void info1(void)
{
    char ele[30];
    int found = 0;

    printf("\033[32mENTER THE ELEMENT'S NAME : \033[0m");
    scanf("%29s", ele);

    /* Convert input to UPPERCASE
       hydrogen  -> HYDROGEN
       Hydrogen  -> HYDROGEN
       HYDROGEN  -> HYDROGEN
       hYdRoGeN  -> HYDROGEN
    */

    for (int j = 0; ele[j] != '\0'; j++)
    {
        ele[j]=toupper((unsigned char)ele[j]);
    }

    for (i = 0; i < 118; i++)
    {
        if (strcmp(atom[i].name, ele) == 0)
        {
            printf("\n");
            printf("\033[34mELEMENT       : %s\033[0m\n", atom[i].name);
            printf("\033[34mSYMBOL        : %s\033[0m\n", atom[i].symbol);
            printf("\033[34mATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34mATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\033[31mELEMENT NOT FOUND!\033[0m\n");
    }

    again();
}

/* =========================
   SEARCH BY SYMBOL
   ========================= */

void info2(void)
{
    char sym[10];
    int found = 0;

    printf("\033[32mENTER THE ELEMENT'S SYMBOL : \033[0m");
    scanf("%9s", sym);

    /* Convert symbol to correct form:
       h  -> H
       HE -> He
       hE -> He
    */

    sym[0] = toupper((unsigned char)sym[0]);

    for (int j = 1; sym[j] != '\0'; j++)
    {
        sym[j] = tolower((unsigned char)sym[j]);
    }

    for (i = 0; i < 118; i++)
    {
        if (strcmp(atom[i].symbol, sym) == 0)
        {
            printf("\n");
            printf("\033[34mELEMENT       : %s\033[0m\n", atom[i].name);
            printf("\033[34mSYMBOL        : %s\033[0m\n", atom[i].symbol);
            printf("\033[34mATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34mATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\033[31mELEMENT NOT FOUND!\033[0m\n");
    }

    again();
}


/* =========================
   SEARCH BY ATOMIC NUMBER
   ========================= */

void info3(void)
{
    int atn;
    int found = 0;

    printf("\033[32mENTER THE ELEMENT'S ATOMIC NUMBER : \033[0m");
    scanf("%d", &atn);

    for (i = 0; i < 118; i++)
    {
        if (atom[i].atomicnum == atn)
        {
            printf("\n");
            printf("\033[34mELEMENT       : %s\033[0m\n", atom[i].name);
            printf("\033[34mSYMBOL        : %s\033[0m\n", atom[i].symbol);
            printf("\033[34mATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34mATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\033[31mELEMENT NOT FOUND!\033[0m\n");
    }

    again();
}


/* =========================
   SEARCH BY ATOMIC WEIGHT
   ========================= */

void info4(void)
{
    float atwt;
    int found = 0;

    printf("\033[32mENTER THE ELEMENT'S ATOMIC WEIGHT : \033[0m");
    scanf("%f", &atwt);

    for (i = 0; i < 118; i++)
    {
        /*
           Small tolerance because floating-point numbers
           should not normally be compared using ==.
        */

        if (fabs(atom[i].atomicwt - atwt) < 0.01)
        {
            printf("\n");
            printf("\033[34mELEMENT       : %s\033[0m\n", atom[i].name);
            printf("\033[34mSYMBOL        : %s\033[0m\n", atom[i].symbol);
            printf("\033[34mATOMIC NUMBER : %d\033[0m\n", atom[i].atomicnum);
            printf("\033[34mATOMIC WEIGHT : %f\033[0m\n", atom[i].atomicwt);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n\033[31mELEMENT NOT FOUND!\033[0m\n");
    }

    again();
}


/* =========================
   SEARCH MENU
   ========================= */

void search(void)
{
    int choice2;

    printf("\n");
    printf("\033[33mSEARCH BY :- \033[0m\n\n");

    printf("\033[34m\t1 -> ELEMENT\033[0m\n");
    printf("\033[34m\t2 -> SYMBOL\033[0m\n");
    printf("\033[34m\t3 -> ATOMIC NUMBER\033[0m\n");
    printf("\033[34m\t4 -> ATOMIC WEIGHT\033[0m\n\n");

    printf("\033[32mYOUR CHOICE : \033[0m");
    scanf("%d", &choice2);

    switch (choice2)
    {
        case 1:
            info1();
            break;

        case 2:
            info2();
            break;

        case 3:
            info3();
            break;

        case 4:
            info4();
            break;

        default:
            printf("\033[31mINVALID CHOICE!\033[0m\n");
            search();
            break;
    }
}


/* =========================
   MAIN MENU
   ========================= */

int main(void)
{
    int choice;

    /* Load all element data */
    table();

    while (1)
    {
        printf("\n\n");
        printf("\033[31;1;51;4m             PERIODIC TABLE             \033[0m\n\n");

        printf("\033[34m1 -> SEARCH ELEMENT\033[0m\n");
        printf("\033[34m2 -> SHOW PERIODIC TABLE\033[0m\n");
        printf("\033[34m3 -> QUIT\033[0m\n\n");

        printf("\033[32mYOUR CHOICE : \033[0m");
        scanf("%d", &choice);

        if (choice == 1)
        {
            search();
        }
        else if (choice == 2)
        {
            Modern_periodic_table();
        }
        else if (choice == 3)
        {
            quit();
        }
        else
        {
            printf("\033[31mINVALID CHOICE!\033[0m\n");
        }
    }

    return 0;
}
