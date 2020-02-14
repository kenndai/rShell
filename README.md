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
![OMT Diagram](images/UML%20Class.png)
## Classes
 - **rShell:** This is the class which contains the main function. It’s also the 'brain' of the rShell program that wires everything together and makes creates the actual program.
 - **Parser:** This class parses the user’s input string into multiple token objects.
 - **Token:** This class contains the raw string of each individual command it also seperates the string into two parts and stores it into an array: the command name and the argument list. For example, ["echo", "hello"]. 
 - **Executer:** This class receives two vectors: a vector of connectors and a vector of Tokens. This class is in charge of determining the boolean logic of which commands to execute based on the connectors given by the user. This class also creates an object for every command and calls the runCmd() when a specific Command object is determined to run.
 - **Command:** This class is in charge of executing the command when determined. It uses system calls to complete this task. It also exits the program if "exit()" is called.
<br/><br/>
