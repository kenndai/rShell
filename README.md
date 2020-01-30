# CS 100 Programming Project
## Project Information
2020 Winter Quarter\
Alexander Trinh SID 861240583\
Kenny Dai SID 862111423
## Introduction
This program is a simplistic shell, or terminal-like, program that takes in commands separated by either <code>||, &&</code> or <code>;</code> which are then executed.<br/><br/>
For example, <code>$ ls -a; echo hello && mkdir test || echo world; git status</code> will display all files including hidden ones, print out ‘hello’, and make a new directory named ‘test’, but will not print out ‘world’ or execute <code>git status</code>.<br/><br/>
In order to complete these tasks, the program most first parse the user input line into separate commands and create the necessary classes in order to complete this task. Finally, with the help of <code>fork(), waitpid(), and execvp()</code> the program will then apply an algorithm to figure out which commands to actually execute.<br/><br/>
## Diagram
![OMT Diagram](images/UMT Diagram)
## Classes
 - **rShell:** This is the class which contains the main function. It’s the only class that strings together and communicates to all of the other classes.
 - **Parser:** This class parses the user’s input string into multiple token objects.
 - **Token:** This class contains the raw string of each individual command and checks if the input is valid or not. It also stores information needed to perform the command.
 - **Output:** This class receives two vectors: a vector of connectors and a vector of Tokens. This class is in charge of determining which commands to execute based on the connectors.
 - **Command:** This class is in charge of executing the command when determined.
<br/><br/>
