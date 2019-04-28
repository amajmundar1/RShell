# CS 100 RShell
Winter 2019  
Abdullah Majmundar - 861233763  
Emily Dixon - 862051249

# Introduction:

program will be able to print a command prompt as well as read in and then execute a line of commands. Parser will separate input into commands and connectors, which will then be processed and executed by their respective classes.


# Diagram:

![UML Diagram](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/blob/master/IMAGES/UML%20Diagram.png)

# Classes:

# Prototypes/Research:

execvp will be used to run the commands, while fork will be used to run those multiple processes simultaneously. waitpid will put processes on hold to ensure they follow the guidelines of the connectors.

# Roadmap:

1. Parser
2. Parser unit testing
3. Base
4. Command
5. Command: evaluate()
6. single command integration testing
7. Operator class
8. Add: evaluate()
9. Or: evaluate()
10. Semi: evaluate()
11. Operator unit testing
12. multiple command integration testing

