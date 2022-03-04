‏String Parser
‏Authored by Yahya Saad
‏==Description==
‏The program is a String Parser, this progrem can read an ordinary sentence which the user input and then will show on the screen: how many words in this sentence and how many characters has the user input in this text, also the user can input more than one sentence. When the user wants to stop using the program, the user must enter the word ("exit") in order to stop the program.
==Program DATABASE==
Each sentence entered in this program, will be saved in a txt file; when the user enter "history"- the program will show all the sentences which entered perversely.
‏How the program ends:
‏By entering the word ("exit"), it reports the successful termination/completion of the program.
‏If the input from the user was Null in the memory, the program will finish processing and reports the abnormal termination of the program (some error or interruption occurs during the execution of the program).

‏==Functions==
‏there is no functions expect the main; in the main the program has 3 main sections- checking all the setuation about the input (exit, help, file), define the history part, counting the words and the characters. 

‏==Program Files==
‏ex1.c: the file contains the main program.

‏==How to compile?==
‏compile: gcc ex1.c -o ex1
‏run: ./ex1

‏==Input==
‏An ordinary sentence with no more than 510 characters

‏==Output:== 
‏int (the number of the words in a giving input from the user)
‏int (the number of the characters in a giving input from the user)
String (when the input is "history" the program will show every sentince which the user has entered perversely and it order in the file)
