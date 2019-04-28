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
    4. evaluate()
5. single command integration testing
6. Operator class
7. Add
   7. evaluate()
8. Or
   8. evaluate()
9. Semi
   9. evaluate()
10. Operator unit testing
11. multiple command integration testing

