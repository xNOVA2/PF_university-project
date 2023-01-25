#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct person
{
    float balance;
    char acc[100];
    char phone[30];
    char password[100];
};

int main()

{
    printf("\n\n");
    time_t now = time(NULL);
    printf("\t\t\t\t\t  %s", ctime(&now));
    system("color 0c");
    FILE *fptr;

    int check;
    float amount;
    int option;
    int option2;
    struct person person1;
    struct person user1;
    char fname[50], pword[50], phone[50];
    printf("\n*********************Welcome***********************");
    printf("\n\n1. Register an account");
    printf("\n2. Login to the account");
    printf("\n\n*************CHOICE***************\t\t");
    scanf("%d", &option);
    if (option == 1)
    {
        system("cls");
        printf("********************************************REGISTER ACCOUNT********************************************");
        printf("\nEnter account number \t");
        scanf("%s", person1.acc);
        printf("Enter  phone number \t");
        scanf("%s", person1.phone);
        printf("Enter pin \t");
        scanf("%s", person1.password);
        if(strlen(person1.password)>4){
            printf("password should be 4 pincode");
            return;
        }
        person1.balance = 0;
        strcpy(fname, person1.phone);

        fptr = fopen(strcat(fname, "suffa"), "w");
        fwrite(&person1, sizeof(struct person), 1, fptr);
        if (fwrite != 0)
        {
            printf("\n\n **************************    Account is register :-)   *********************** ");
        }
        else
        {
            printf("System error try again later");
        }
        fclose(fptr);
    }

    if (option == 2)
    {
        system("cls");
        printf("\nEnter your phone number \t");
        scanf("%s", phone);
        printf("\nEnter pin \t");
        scanf("%s", pword);
        strcpy(fname, phone);
        fptr = fopen(strcat(fname, "suffa"), "r");

        if (fptr == NULL)
        {
            printf("\n Account not register ");
        }
        else
        {

            fread(&person1, sizeof(struct person), 1, fptr);
            fclose(fptr);
            check = strcmp(pword, person1.password);
            if (check == 0)
            {
                printf("\npassword match");
                char continuee = 'y';
                while (continuee == 'y')
                {
                    system("cls");
                    printf("\n Press 1 to check balance \t");
                    printf("\n Press 2 to deposit money \t");
                    printf("\n Press 3 to withdraw money\t");
                    printf("\n Press 4 to online balance transfer \t");

                    printf("\n*********************************** Press any number :) ************************  \n");
                    scanf("%d", &option2);

                    if (option2 == 1)
                    {
                        printf("\n Your current balance is Rs %.2f", person1.balance);
                    }
                    else if (option2 == 2)
                    {
                        printf("\n Enter the amount you wanna deposit \t");
                        scanf("%f", &amount);
                        person1.balance = person1.balance + amount;
                        fptr = fopen(fname, "w");
                        fwrite(&person1, sizeof(struct person), 1, fptr);
                        if (fwrite != NULL)
                            printf("succefully deposit");
                        fclose(fptr);
                    }
                    else if (option2 == 3)
                    {
                        printf("\n Enter the amount  \t");
                        scanf("%f", &amount);
                        if (amount < 500)
                            printf("\nEnter above Rs 500");
                        else
                        {
                            if (amount > person1.balance)
                                printf("\nInsufficant Balance");

                            else
                            {
                                person1.balance = person1.balance - amount;
                                fptr = fopen(fname, "w");
                                fwrite(&person1, sizeof(struct person), 1, fptr);
                                if (fwrite != NULL)
                                    printf("succefully withdraw Rs %.2f", amount);
                                else
                                    printf("enter amount please");
                                fclose(fptr);
                            }
                        }
                    }

                    else if (option2 == 4)
                    {
                        printf("\n please enter the phone number to which you wanna transfer the money \t");
                        scanf("%s", &phone);
                        printf("please enter the amount you wanna trasnfer");
                        scanf("%f", &amount);
                        strcpy(fname, phone);
                        fptr = fopen(strcat(fname, "suffa"), "r");
                        if (fptr == NULL)
                            printf("Account not register");
                        else
                        {
                            fread(&user1, sizeof(struct person), 1, fptr);
                            fclose(fptr);
                            if (amount > person1.balance)
                                printf("\ninsufficant balance");
                            else
                            {
                                fptr = fopen(fname, "w");
                                user1.balance = user1.balance + amount;
                                fwrite(&user1, sizeof(struct person), 1, fptr);
                                fclose(fptr);

                                if (fwrite != NULL)
                                {
                                    printf("you have succesfully transfer the money");
                                    strcpy(fname, person1.phone);
                                    fptr = fopen(strcat(fname, "suffa"), "w");
                                    person1.balance = person1.balance - amount;
                                    fwrite(&person1, sizeof(struct person), 1, fptr);
                                    fclose(fptr);
                                }
                            }
                        }
                    }

                    printf("\n Do you wanna continue transaction [y/n]\t");
                    scanf(" %c", &continuee);
                }
            }
            else
            {
                printf("\nwrong password");
            }
        }
    }

    return 0;
}

