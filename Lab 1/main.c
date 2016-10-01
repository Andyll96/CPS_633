#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 25
#define MAX_READIN 100
#define MAX_USERID 32
#define MAX_PASS 12

void databaseInit();
void enterUserID();
void enterPassword();
void printDatabase();

int i, correct = 1, usernameLength, passwordLength;
char ***databaseTable;
char **userIdDB;
char **passwordDB;

char *tempUserId;
char*tempPassword;

int main()
{
    databaseInit();

    printf("Welcome to CPS_633 Lab 1.\n");

    /*-------------------------USERNAME-----------------*/

    enterUserID();

    /*-------------------------USERNAME-----------------*/
    correct = 1;
    /*-------------------------PASSWORD-----------------*/
   enterPassword();
    /*-------------------------PASSWORD-----------------*/

    printDatabase();

    printf("done\n");

    return 0;
}

void databaseInit()
{

     databaseTable = (char***)malloc(sizeof(char) * 2);
     userIdDB = (char**)malloc(sizeof(char) * MAX_RECORDS);
     passwordDB  = (char**)malloc(sizeof(char) * MAX_RECORDS);
    
     tempUserId = (char*)malloc(sizeof(char) * MAX_USERID);
     tempPassword = (char*)malloc(sizeof(char) *MAX_PASS);

     for(i = 0; i <= MAX_RECORDS + 1; i++)
    {
        userIdDB[i] = malloc(sizeof(char) * MAX_USERID);
        passwordDB[i] = malloc(sizeof(char) * MAX_PASS);
    }
    databaseTable[0] = userIdDB;
    databaseTable[1] = passwordDB;
}

void enterUserID()
{
    while(correct == 1){
        printf("Please Enter Your Username ID: ");
        fgets(tempUserId,MAX_READIN, stdin);
       
        usernameLength = strlen(tempUserId) - 1;
        printf("Your Username ID is %d characters long\n", usernameLength);

        if(usernameLength > 32)
        {
            printf("This Username ID is longer than 32 characters\n");
            correct = 1;
        }
        else if(usernameLength < 4)
        {
            printf("This Username ID is shorter than 4 characters\n");
            correct = 1;
        }
        else
        {
            int j;
            for(j = 0; j <= MAX_RECORDS; j++)
            {
                if(databaseTable[0][j] != NULL)
                {
                    userIdDB[j] = tempUserId;
                    printf("%s is stored\n", databaseTable[0][j]);
                    break;
                }
            }
            correct = 0;
        }
    }
}

void enterPassword()
{
 while(correct == 1)
    {
        printf("Please Enter Your Password: ");
        fgets(tempPassword, MAX_READIN, stdin);

        passwordLength = strlen(tempPassword) - 1;
        
        if(passwordLength > 12)
        {
            printf("This password is too long, the characters after the 12th has been cut off \n");
            int k;
            for(k = 0; k <= MAX_RECORDS; k++)
            {
                passwordDB[k] = tempPassword;
                printf("%s is stored\n", databaseTable[1][k]);
                break;
            }
        }
        else 
        {
            int k;
            for(k = 0; k <= MAX_RECORDS; k++)
            {
                passwordDB[k] = tempPassword;
                printf("%s is stored\n", databaseTable[1][k]);
                break;
            }
            correct = 0;
        }
    }
}

void printDatabase()
{
    int i,j;

    for(i = 0; i <= 2; i++)
    {
        for(j = 0; j <= 2; j++)
        {
            printf("databaseTable[%d][%d] = %s\n",i,j,databaseTable[i][j]);
        }
    }
}

