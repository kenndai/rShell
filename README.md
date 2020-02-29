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
 - **Token:** This is the pure virtual class which contains the necessary components needed by each sub Token class.
 - **Executer:** This class receives the token list which was parsed by the Parser class. It then applies certain algorithms to the tokens, such as mirror, shunting yard, mirror, and then creates tree. The executer then calls run() on the tokens.
 - **AND:** This class is created when the parser detects the <code>&&</code> operator. It also contains a string value of "AND" which can be referenced to when trying to determine which object it is.
 - **OR:** This class is created when the parser detects the <code>||</code> operator. It also contains a string value of "OR" which can be referenced to when trying to determine which object it is.
 - **SEMI:** This class is created when the parser detects the <code>;</code> operator. It also contains a string value of "SEMI" which can be referenced to when trying to determine which object it is.
 - **PAREN:** This class is created when the parser detects either<code>(</code> or <code>)</code> operator. It also contains a string value of the operator which can be referenced to when trying to determine which object it is.
 - **CMD:** This class is created when the parser detects command such as <code>echo "hello world"</code>. It also parses the string based on the spaces and puts it into an info string array. CMD also contains the run function which uses system calls to perform the given command.
<br/><br/>
