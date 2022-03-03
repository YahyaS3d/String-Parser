//name: Yahya Saad
//id: 322944869
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX 510//the maximum length which the sentence can have
int main() {
    char str[MAX];//the sentence from the user
    FILE* file;
    while(1){
        int CountWords = 0;
        int CountChars = 0;
        int CountLine = 0;
        file = fopen("file.txt", "a+");
        printf("Enter String, or “exit” to end program: \n");
        //---check if the entered string is a null!---
        if(fgets(str, MAX, stdin)==NULL) {
            perror("enter a sentence");
            continue;
        }
        str[strlen(str) - 1] = '\0';// put /0 at the end of the giving sentence
        if(file == NULL){
            printf("Error opening the file.\n");
            exit(1);
        }

        //---exit if the input is exit---

        if(strcmp(str , "exit" )== 0){
            break;
        }

        if(strcmp(str , "history" )== 0){
            char * line = NULL;
            size_t length = 0;
            ssize_t read;
            while ((read = getline(&line, &length, file)) != -1) {
                printf("%d: %s", CountLine,line);
                CountLine++;
            }
            if (line)
                free(line);
            fseek(file , 0 , SEEK_SET);
        }
        else{
            if(str[0] == '\0'){
               continue;
            }else{
                fprintf(file, "%s\n", str);
            }
            int i;
            for (i = 0; str[i] != '\0'; i++) {// this Loop count how many words in the String
                if (str[i] != ' ' && (str[i+1] == ' ' || str[i+ 1] == '\0')) {// this condition checks  if the char is not a space and the char after it is a space or the end of sentence
                    CountWords++;
                }
                if (str[i] != ' ') {// this condition will check if the char is not equal to space
                    CountChars++;
                }

            }
            //---print how many word are in the sentence---
            if(CountWords!=0){
                printf("%d words \n", CountWords);
                if(str[0] == '\0'){
                    continue;
                }else
                    printf("%d chars \n", CountChars);// print how many characters in a giving sentence
            }
            fclose(file);
        }
    }
    return 0;
}
