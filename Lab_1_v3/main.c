#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000
#define MAX_INPUT 40

void E(char *in1, char *in2, char *in3);
void hasher();
void writeFile();
int inputPass(int i, int newpasswrd);
void inputID();
void userInput();
void printDB();
void readFile();
void hInit();
void inputInit();
void DBInit();
void init();

FILE *fp;

char **IDArray;
char **passwordArray;

char *IDInput;
char *passInput;

char *h1In;
char *h2In;
char *h3In;

char *h1Out;
char *h2Out;
char *h3Out;

int n;

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

void E(char *in1, char *in2, char *in3)
{
    h1Out[0] = (in1[0] & 0x80) ^ (((in1[0] >> 1) & 0x7F) ^ ((in1[0]) & 0x7F));
    h1Out[1] = ((in1[1] & 0x80) ^ ((in1[0] << 7) & 0x80)) ^ (((in1[1] >> 1) & 0x7F) ^ ((in1[1]) & 0x7F));
    h1Out[2] = ((in1[2] & 0x80) ^ ((in1[1] << 7) & 0x80)) ^ (((in1[2] >> 1) & 0x7F) ^ ((in1[2]) & 0x7F));
    h1Out[3] = ((in1[3] & 0x80) ^ ((in1[2] << 7) & 0x80)) ^ (((in1[3] >> 1) & 0x7F) ^ ((in1[3]) & 0x7F));

    h2Out[0] = (in2[0] & 0x80) ^ (((in2[0] >> 1) & 0x7F) ^ ((in2[0]) & 0x7F));
    h2Out[1] = ((in2[1] & 0x80) ^ ((in2[0] << 7) & 0x80)) ^ (((in2[1] >> 1) & 0x7F) ^ ((in2[1]) & 0x7F));
    h2Out[2] = ((in2[2] & 0x80) ^ ((in2[1] << 7) & 0x80)) ^ (((in2[2] >> 1) & 0x7F) ^ ((in2[2]) & 0x7F));
    h2Out[3] = ((in2[3] & 0x80) ^ ((in2[2] << 7) & 0x80)) ^ (((in2[3] >> 1) & 0x7F) ^ ((in2[3]) & 0x7F));

    h3Out[0] = (in3[0] & 0x80) ^ (((in3[0] >> 1) & 0x7F) ^ ((in3[0]) & 0x7F));
    h3Out[1] = ((in3[1] & 0x80) ^ ((in3[0] << 7) & 0x80)) ^ (((in3[1] >> 1) & 0x7F) ^ ((in3[1]) & 0x7F));
    h3Out[2] = ((in3[2] & 0x80) ^ ((in3[1] << 7) & 0x80)) ^ (((in3[2] >> 1) & 0x7F) ^ ((in3[2]) & 0x7F));
    h3Out[3] = ((in3[3] & 0x80) ^ ((in3[2] << 7) & 0x80)) ^ (((in3[3] >> 1) & 0x7F) ^ ((in3[3]) & 0x7F));

    sprintf(passInput, "%s%s%s", h1Out, h2Out, h3Out);
}

void hasher()
{
    int i = 0;
    while (passInput[i])
    {
        passInput[i] = toupper(passInput[i]);
        i++;
    }

    memcpy(h1In, passInput, 4);
    memcpy(h2In, passInput + 4, 4);
    memcpy(h3In, passInput + 8, 4);

    E(h1In, h2In, h3In);
    //printf("\nh1Out: %s\nh2Out: %s\nh3Out: %s\n", h1Out, h2Out, h3Out);
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
                        hasher();
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
                    int j;
                    for (j = strLength; j < 12; j++) //Pads password with "-"
                    {
                        passInput[j] = '-';
                    }
                    hasher();
                    strncpy(passwordArray[record], passInput, 12);
                    return 0;
                }
                else //If record not empty, compare
                {
                    int j;
                    for (j = strLength; j < 12; j++) //Pads password with "-"
                    {
                        passInput[j] = '-';
                    }
                    hasher();
                    if (strcmp(passInput, passwordArray[record]) == 0) //If match
                    {
                        printf("correct password\n");

                        strncpy(passwordArray[record], passInput, 12);
                        return 0;
                    }
                    else //If not match
                    {
                        if (newpass == 0) // If a match, and
                        {
                            strncpy(passwordArray[record], passInput, 12);
                            return 0;
                        }
                        else if (newpass == 1) // If not a match
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
                        n = 5;
                        int cmpr;
                        while (n > 0)
                        {
                            printf("You have %d attempts \n", n );
                            cmpr = inputPass(i, 1);
                            if (cmpr == 1 && n > 0) //wrong attempt, still has n
                            {
                                n--;
                                continue;
                            }

                            else if (cmpr == 0 && n > 0)
                            {
                                printf("Success!!\nTime for a new Password\n");
                                int test = 1;
                                while (test == 1)
                                {
                                    test = inputPass(i, 0);
                                }
                                break;
                            }
                        }
                        if (cmpr == 1 && n == 0) //failed 5 n
                        {
                            printf("Too many unseccessful attempts - your account is locked");
                            break;
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
    fp = fopen("Database_Table.txt", "a+");

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

void hInit()
{
    h1In = (char *)malloc(sizeof(char) * 4);
    h2In = (char *)malloc(sizeof(char) * 4);
    h3In = (char *)malloc(sizeof(char) * 4);
    h1Out = (char *)malloc(sizeof(char) * 4);
    h2Out = (char *)malloc(sizeof(char) * 4);
    h3Out = (char *)malloc(sizeof(char) * 4);
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
    hInit();
}
