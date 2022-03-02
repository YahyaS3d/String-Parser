String Parser
Authored by Yahya Saad
322944869
==Description==
The program is a String Parser, this progrem can read an ordinary sentence which the user input and then will show on the screen: how many words in this sentence and the length for each word in this text, also the user can input more than one sentence. When the user wants to stop using the program, the user must enter the word ("exit") in order to stop the program.
How the program ends:
By entering the word ("exit"), it reports the successful termination/completion of the program.
If the input from the user was Null in the memory, the program will finish processing and reports the abnormal termination of the program (some error or interruption occurs during the execution of the program).

Functions:
Two main functions:
1) CountWords: this method receives a pointer to array of characters (str) order to count how many words in the sentence and return the count.
2) GetWord: this method receives a pointer to array of characters (str), the method prints every word in the text with it's length.

==Program Files==
ex1.c: the file contains the main and the function which is used to build the program.

==How to compile?==
compile: gcc ex1.c -o ex1
run: ./ex1

==Input:==
An ordinary sentence with no more 510 characters

==Output:== 
int (the number of the words in the text) 
int and array of characters(every word in the text with it length)