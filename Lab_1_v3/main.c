#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000
#define MAX_INPUT 40

void writeFile();
int inputPass(int i, int newpasswrd);
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

    inputID();
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

int inputPass(int i, int newpasswrd)
{
    int correct = 1, strLength;
    int record = i;
    int newpass = newpasswrd;

    printf("Please Enter Your Password (no special characters): ");
    fgets(passInput, MAX_INPUT, stdin);
    strLength = strlen(passInput) - 1;

    if (strLength > 0 && passInput[strLength] == '\n')
    {
        passInput[strLength] = '\0';
    }

    while (correct)
    {
        int k;
        int specialCase = 1;
        for (k = 0; k <= strLength; k++) //Searches for special characters
        {
            switch (passInput[k])
            {
            case '~':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '!':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '`':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '@':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '#':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '$':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '%':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '^':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '&':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '*':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '(':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case ')':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '-':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '_':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '=':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '+':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '[':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case ']':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '{':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '}':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '|':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '\\':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case ':':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case ';':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;

            case '"':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case ',':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '<':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '.':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '>':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '?':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            case '/':
                printf("Special Character(s) Found\n");
                specialCase = 0;
                break;
            }
            if (specialCase == 0)
                break;
        }
        if (specialCase != 0) //If there are no special characters
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
            else //Password acceptably shorter than 12 characters
            {
                if (passwordArray[record][0] == '\0') //If record is empty
                {
                    strncpy(passwordArray[record], passInput, 12);
                    return 0;
                }
                else //If record not empty, compare
                {
                    int r;
                    for (r = 0; r < 12; r++) //unpads for compairison
                    {
                        if (passwordArray[record][r] == '-')
                            passwordArray[record][r] = '\0';
                    }

                    if (strcmp(passInput, passwordArray[record]) == 0) //If match
                    {
                        printf("correct password\n");
                        int j;
                        for (j = strLength; j < 12; j++) //Pads password with "-"
                        {
                            passInput[j] = '-';
                        }
                        strncpy(passwordArray[record], passInput, 12);
                        return 0;
                    }
                    else //If not match
                    {
                        if (newpass == 0)
                        {
                            int j;
                            for (j = strLength; j < 12; j++) //Pads password with "-"
                            {
                                passInput[j] = '-';
                            }
                            strncpy(passwordArray[record], passInput, 12);
                            return 0;
                        }
                        else if (newpass == 1)
                        {
                            return 1;
                        }
                    }
                }
                correct = 0;
            }
        }
        else //If there are special characters
        {
            return 1;
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
        if (strLength > 32) //If longer than 32 characters
        {
            printf("This Username ID is longer than 32 characters\n");
            printf("Please Enter Your Username ID: ");
            fgets(IDInput, MAX_INPUT, stdin);

            strLength = strlen(IDInput) - 1;

            if (strLength > 0 && IDInput[strLength] == '\n')
                IDInput[strLength] = '\0';
        }
        else if (strLength < 4) //If shorter than 4 characters
        {
            printf("This Username ID is shorter than 4 characters\n");
            printf("Please Enter Your Username ID: ");
            fgets(IDInput, MAX_INPUT, stdin);

            strLength = strlen(IDInput) - 1;

            if (strLength > 0 && IDInput[strLength] == '\n')
                IDInput[strLength] = '\0';
        }
        else //If acceptable length
        {
            int i;
            for (i = 0; i < MAX_RECORDS; i++)
            {
                if (IDArray[i][0] != '\0') //If element occupied, compare
                {
                    if (strcmp(IDArray[i], IDInput) == 0) // If the same
                    {
                        printf("Match Found\n");
                        int attempts = 4, cmpr;
                        while (attempts > -1)
                        {
                            printf("You have %d attempts \n", attempts + 1);
                            cmpr = inputPass(i, 1);
                            if (cmpr == 1 && attempts > 0) //wrong attempt, still has attempts
                            {
                                attempts--;
                                continue;
                            }
                            else if (cmpr == 1 && attempts == 0) //failed 5 attempts
                            {
                                printf("failure, account will be erased");
                                break;
                            }
                            else if (cmpr == 0 && attempts > 0)
                            {
                                printf("success!!\nTime for a new Password\n");
                                int test = 1;
                                while (test == 1)
                                {
                                    test = inputPass(i, 0);
                                }
                                break;
                            }
                        }
                        correct = 0;
                        break;
                    }
                    else //If not the same
                    {
                        continue;
                    }
                }
                else //If element empty, insert
                {
                    strcpy(IDArray[i], IDInput);
                    int test = 1;
                    while (test == 1)
                    {
                        test = inputPass(i, 0);
                    }
                    break;
                }
            }
            correct = 0;
        }
    }
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
