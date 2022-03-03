//NAME: Yahya Saad
//ID: 322944869
#include <stdio.h>

#include <stdlib.h>

#include "string.h"

#define MAX 510 //the maximum length which the sentence can have
int main() {
  char str[MAX]; //the sentence from the user
  FILE * file; //file.txt
  while (1) {
    int CountWords = 0; //how many wards in each sentence
    int CountChars = 0; //how many character in every sentence
    int CountLine = 0; // how many lines in the file - to set the number next to the line when we print history
    file = fopen("file.txt", "a+");
    printf("Enter String, or “exit” to end program: \n");
    //---check if the entered string is a null!---
    if (fgets(str, MAX, stdin) == NULL) {
      perror("enter a sentence");
      continue;
    }
    str[strlen(str) - 1] = '\0'; // put /0 at the end of the giving sentence
    //---check if the file doesnt open successfully!---
    if (file == NULL) {
      printf("Error opening the file.\n");
      exit(1);
    }

    //---exit if the input is exit---

    if (strcmp(str, "exit") == 0) {
      break;
    }
    //---show file content "history" if the input is history---
    if (strcmp(str, "history") == 0) {
      char * line = NULL;
      size_t length = 0;
      ssize_t read;
      while ((read = getline( & line, & length, file)) != -1) {
        printf("%d: %s", CountLine, line);
        CountLine++;
      }
      if (line)
        free(line); // to get a new line after the previous one
      //set the pointer back to the beginning of the file
      fseek(file, 0, SEEK_SET);
    } else {
      //check if the input is an empty string or have spaces, so we will not enter it in the file and also will not be shown un count words and count characters then!!
      if (str[0] == '\0' || str[0] == ' ') {
        continue;
      } else {
        //print the user input into the file
        fprintf(file, "%s\n", str);
      }
      //---Count Words and Count Characters section---
      int i;
      for (i = 0; str[i] != '\0'; i++) { //MAIN LOOP: passing on the user input string onetime in order to count the words and the chars
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) { // this condition checks  if the char is not a space and the char after it is a space or the end of sentence
          CountWords++;
        }
        if (str[i] != ' ') { //check if the char is not equal to space
          CountChars++;
        }

      }
      //---print how many word are in the sentence---
      if (CountWords != 0) {
        printf("%d words \n", CountWords);
        if (str[0] == '\0') {
          continue;
        } else
          //---print how many characters are in the sentence---
          printf("%d chars \n", CountChars);
      }
      fclose(file);
    }
  }
  return 0;
}
