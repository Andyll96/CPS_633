#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 40
#define MAX_RECORDS 30
#define MAX_COLUMNS 2   

void readFile();
void writeFile();
void Init();
void DBInit();
void inputInit();
void inputID();
void inputPassword();
void printDB();
void deInit();

FILE *fp;

char **IDArray;
char **passwordArray;

char *IDInput;
char *passwordInput;

int main(){
    printf("\n");
    Init();
    readFile();
   
    printf("\n\nWelcome to CPS_633, Lab 1 \n\n");
    //inputID();
    //inputPassword();
    printDB();

    //writeFile();

    //deInit();
    return 0;
}

void readFile(){
    int strLength;
    fp = fopen("database Table.txt", "r");
    char line[256];

    if(fp == NULL){ //error
        perror("Error in opening file");
    }
    else{ //The file exists
        int i = 0;
        while(!feof(fp)){
            if(fgets(line,sizeof(line),fp) == NULL){
                break;
            }
            else{
                printf("line: %s", line);
                sscanf(line,"%s\t%s",IDInput,passwordInput);
                strcpy(IDArray[i],IDInput);
                strcpy(passwordArray[i],passwordInput);
                i++;
            }
        }
    }
        fclose(fp);
}

void writeFile(){
    fopen("database Table.txt", "w");
    int i;
    for(i=0; i<=MAX_RECORDS; i++){
        if(IDArray[i] != NULL){
            fprintf(fp,"%s\t%s\n",IDArray[i], passwordArray[i]);
            
        }
        else{
            break;
        }
    }
    fclose(fp);
}

void Init(){
    DBInit();
    inputInit();
}

void DBInit(){
    IDArray = (char**)malloc(sizeof(char) * MAX_RECORDS);
    passwordArray = (char **)malloc(sizeof(char) * MAX_RECORDS);
}

void inputInit(){
    IDInput = (char*)malloc(sizeof(char) * MAX_INPUT);
    passwordInput = (char*)malloc(sizeof(char) * MAX_INPUT);
}

void inputID(){
    int correct = 1, strLength;
    
    printf("Please Enter Your Username ID: ");
    fgets(IDInput,MAX_INPUT,stdin);
    strLength = strlen(IDInput) - 1;
    //printf("Length: %d\n",strLength);
    if(strLength > 0 && IDInput[strLength] == '\n'){
        IDInput[strLength] = '\0';
    }

    while(correct == 1){
        if(strLength > 32){
            printf("This Username ID is longer than 32 characters\n");
            break;
        }
        else if(strLength < 4){
            printf("This Username ID is shorter than 4 characters\n");
            break;
        }
        else{
            int j;
            for(j=0;j<MAX_RECORDS; j++){
                if(IDArray[j] == NULL){
                    IDArray[j] = IDInput;
                    break;
                }
                else{
                    continue;
                }
            }
            correct = 0;
        }
    }
}

void inputPassword(){
    int correct = 1, strLength;

    printf("Please Enter Your Password: ");
    fgets(passwordInput, MAX_INPUT -1, stdin);
    strLength = strlen(passwordInput) - 1;
    //printf("Length: %d\n", strLength);
    if(strLength > 0 && passwordInput[strLength] == '\n'){
        passwordInput[strLength] = '\0';
    }

    while(correct == 1){
        if(strLength > 12){
            printf("This password is too long, the characters after the 12th has been cut off\n");
            int j;
            for(j=0;j<=MAX_RECORDS;j++){
                if(passwordArray[j] ==NULL){
                    passwordArray[j] = passwordInput;
                    break;
                }
                else{
                    continue;
                }
            }
            correct = 0;
        }
        else{
            int j;
            for(j=0;j<=MAX_RECORDS;j++){
                if(passwordArray[j] ==NULL){
                    passwordArray[j] = passwordInput;
                    break;
                }
                else{
                    continue;
                }
            }
            correct = 0;
        }
    }

}

void printDB(){
    printf("\nUsername\tPassword\n");
    int i;
    for(i=0; i<=3; i++){
        if(IDArray[i] != NULL){
            printf("%s\t%s\n",IDArray[i], passwordArray[i]);
        }
        else{
            break;
        }
    }
}

void deInit(){
    free(IDArray);
    free(passwordArray);

    free(IDInput);
    free(passwordInput);

}