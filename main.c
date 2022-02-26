//name: Yahya Saad
//id: 322944869

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX 510//the maximum length which the sentence can have

//Pointer parameter 'str' can be pointer to const --> str must be const
void CountWords(const char str[]); //calculate how many words in a giving sentence
int CountLines(FILE* file);
void CountChars(const char str[],char temp[],char* text);//calculate how many letters in each word
void PrintHistory(FILE* file, int lines);
int main() {
    char str[MAX];// String we want to enter by use fgets
    char temp[MAX]; //temp string
    char *text = NULL;
    int lines;
    FILE* file;
    int size;
    while(1){

        printf("Enter String, or “exit” to end program: \n");
        //---check if the entered string is a null!---
        if(fgets(str, MAX, stdin)==NULL) {
            perror("enter a sentence");
            continue;
        }
        str[strlen(str) - 1] = '\0';

        file = fopen("file.txt", "a+");
        if(file == NULL){
            printf("Error opening the file.\n");
            exit(1);
        }
        //---exit if the input is exit---
        if(strcmp(str , "exit" )== 0){
            break;
        }

        if(strcmp(str , "history" )!=0 && strcmp(str , "exit" )!= 0 ){
            fputs(str,file);
            fputs("\n",file);
        }
        if(strcmp(str, "history") == 0){
            if (NULL != file) {
                fseek(file, 0, SEEK_END);
                size = ftell(file);

                if (0 == size) {
                    lines = 0;
                }else
                lines = CountLines(file);

                /* Get each line until there are none left */
//                char *path;
//                char line[MAX_LINE_LENGTH] = {0};
//                unsigned int line_count = 0;
//                while (fgets(str, MAX, file)) {
//                    /* Print each line */
//                    printf("line[%06d]: %s", ++line_count, str);
//
//                    /* Add a trailing newline to lines that don't already have one */
//                    if (str[strlen(str) - 1] != '\n')
//                        printf("\n");
//                }
//
//                /* Close file */
//                if (fclose(file)) {
//                    return EXIT_FAILURE;
//                    perror(file);
//                }

            }
            int l;
         for(l=0;l<=lines;l++){
             printf("%d: %s", lines, str);
         }
            fclose(file);
        }else{
            CountWords(str);
            if(str[0] == '\0'){
                continue;
            }else
                CountChars(str,temp,text);
        }
        }

    return 0;
}
void CountWords(const char str[]) { // the method will calculate how many words we entered through the string
    int i;
    int count = 0;
    for (i = 0; str[i] != '\0'; i++) {// this Loop count how many words in the String
        if (str[i] != ' ' && (str[i+1] == ' ' || str[i+ 1] == '\0')) {// this condition checks  if the char is not a space and the char after it is a space or the end of sentence
            count++;


        }

    }
    //---print how many word are in the sentence---
        if(count!=0)
            printf("%d words \n", count);

}

void CountChars( const char str[], char temp[], char *text) {// this method will cut the sentence into words and calculate how many letters are in them
    strcpy(temp, "");
    int counter = 0;
    int k = 0;// use k  to move on temp indexes
    int i;
    for (i = 0; str[i] != '\0'; i++) {// this loop will cut the sentence into words and calculate how many letters are in them
        if (str[i] != ' ') {// this condition will check if the char is not equal to space
            counter++;
            temp[k] = str[i];//put the char in temp
            k++;
        }
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {// this condition checks  if the char is not a space and the char after it is a space or the end of sentence
            temp[k] = '\0';//will mark the end of a temp
            text = (char *) malloc(sizeof(char) * (counter + 1));// array there length is the char size * (the size of the temp+1('\0'))
            if (text == NULL) // condition If dynamic allocation failed
                {
                puts("malloc is failed\n");
                exit(1);// exit the code
                }
            strcpy(text, temp);// copy from temp to word
            k = 0;
            strcpy(temp, "");
            free(text);// free memory
        }
    }
    printf("%d chars \n", counter);// print how many characters in a giving sentence
}
int CountLines(FILE* file){
    char ch;
    int count=0;
    file = fopen( "file.txt", "a+");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(file)) != EOF)
    {
        /* Check new line */
        if (ch == '\n' || ch == '\0')
            count++;
    }
    fclose(file);
    return count;
}
void PrintHistory(FILE* file, int lines){

}
