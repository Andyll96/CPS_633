#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000
#define MAX_INPUT 40

void writeFile();
void inputPass();
void inputID();
void userInput();
void printDB();
void readFile();
void inputInit();
void DBInit();
void init();

FILE *fp;

char **IDArray;
char **passwordArray;

char *IDInput;
char *passInput;

int main()
{
    init();
    readFile();

    printf("\n\n\tWelcome to CPS_633, Lab 1\t\n\n");

    userInput();
    writeFile();
    printDB();

    return 0;
}

void writeFile()
{
    fp = fopen("Database_Table.txt", "w");
    int i;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (IDArray[i][0] != '\0')
        {
            fprintf(fp, "%s\t%s\n", IDArray[i], passwordArray[i]);
        }
        else
        {
            break;
        }
    }
    fclose(fp);
}

void printDB()
{
    printf("\nUsername\tPassword\n");
    int i;
    int databaseLength = 0;

    for (i = 0; i <= MAX_RECORDS; i++)
    {
        if (IDArray[i][0] != '\0')
        {
            printf("%s\t\t%s\n", IDArray[i], passwordArray[i]);
        }
        else
        {
            break;
        }
    }
}

void inputPass()
{
    int correct = 1, strLength;

    printf("Please Enter Your Password (no special characters): ");
    fgets(passInput, MAX_INPUT, stdin);
    strLength = strlen(passInput) - 1;

    if (strLength > 0 && passInput[strLength] == '\n')
    {
        passInput[strLength] = '\0';
    }

    while (correct)
    {
        if (strLength > 12) //Password longer than 12 characters
        {
            printf("This password is too long, the characters after the 12th has been cut off\n");
            int i;
            for (i = 0; i < MAX_RECORDS; i++)
            {
                if (passwordArray[i][0] == '\0')
                {
                    strncpy(passwordArray[i], passInput, 12);
                    break;
                }
                else
                {
                    continue;
                }
            }
            correct = 0;
        }
        else //Password shorter than 12 characters
        {
            int i, j;
            for (j = strLength; j <= 12; j++)
            {
                passInput[j] = '-';
            }

            for (i = 0; i < MAX_RECORDS; i++)
            {
                if (passwordArray[i][0] == '\0')
                {
                    strncpy(passwordArray[i], passInput, 12);
                    break;
                }
                else
                {
                    continue;
                }
            }
            correct = 0;
        }
    }
}

void inputID()
{
    int correct = 1, strLength;

    printf("Please Enter Your Username ID: ");
    fgets(IDInput, MAX_INPUT, stdin);
    strLength = strlen(IDInput) - 1;

    if (strLength > 0 && IDInput[strLength] == '\n')
        IDInput[strLength] = '\0';

    while (correct)
    {
        if (strLength > 32)
        {
            printf("This Username ID is longer than 32 characters\n");
            printf("Please Enter Your Username ID: ");
            fgets(IDInput, MAX_INPUT, stdin);

            strLength = strlen(IDInput) - 1;

            if (strLength > 0 && IDInput[strLength] == '\n')
                IDInput[strLength] = '\0';
        }
        else if (strLength < 4)
        {
            printf("This Username ID is shorter than 4 characters\n");
            printf("Please Enter Your Username ID: ");
            fgets(IDInput, MAX_INPUT, stdin);

            strLength = strlen(IDInput) - 1;

            if (strLength > 0 && IDInput[strLength] == '\n')
                IDInput[strLength] = '\0';
        }
        else
        {
            int i;
            for (i = 0; i < MAX_RECORDS; i++)
            {
                if (IDArray[i][0] == '\0')
                {
                    strcpy(IDArray[i], IDInput);
                    break;
                }
                else
                {
                    continue;
                }
            }
            correct = 0;
        }
    }
}

void userInput()
{
    inputID();
    inputPass();
}

void readFile()
{
    fp = fopen("Database_Table.txt", "r");

    char line[MAX_INPUT];
    if (fp == NULL)
    {
        perror("Error in opening file");
    }
    else
    {
        int i = 0;
        while (!feof(fp))
        {
            if (fgets(line, sizeof(line), fp) == NULL)
            {
                break;
            }
            else
            {
                sscanf(line, "%s\t%s", IDInput, passInput);
                strcpy(IDArray[i], IDInput);
                strcpy(passwordArray[i], passInput);
                i++;
            }
        }
    }
    fclose(fp);
}

void inputInit()
{
    IDInput = (char *)malloc(sizeof(char) * MAX_INPUT);
    passInput = (char *)malloc(sizeof(char) * MAX_INPUT);
}

void DBInit()
{
    IDArray = (char **)malloc(sizeof(char *) * MAX_RECORDS);
    passwordArray = (char **)malloc(sizeof(char *) * MAX_RECORDS);

    int i, j;
    for (i = 0; i < MAX_RECORDS; i++)
    {
        IDArray[i] = (char *)malloc(sizeof(char) * MAX_INPUT);
        passwordArray[i] = (char *)malloc(sizeof(char) * MAX_INPUT);
        for (j = 0; j < MAX_INPUT; j++)
        {
            IDArray[i][j] = '\0';
            passwordArray[i][j] = '\0';
        }
    }
}

void init()
{
    DBInit();
    inputInit();
}