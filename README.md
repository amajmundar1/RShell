# CS 100 RShell
Winter 2019  
Abdullah Majmundar - 861233763  
Emily Dixon - 862051249

# Introduction:

The goal of this program is to replicate the functionality of an RSHELL to a limited extent. It will be able to execute basic commands and use the "&&", "||" and ";" operators.

The input will be read as a string and then tokenized based on operators first. It will be fitted into an expression tree and evaluated according to the rules described in the Add, Or and Semi classes.

The evaluation process will call Parser once again and this time tokenize based on white space (Seperating words)

The vector will then be fed into the Evaluate class where the first string will be checked for validity. If found, it will contiue to check the rest of the string matches the syntax of the command. Then it will execute. if it does not, it will return an error message based on where it fails.

# Diagram:

![UML Diagram](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/blob/master/IMAGES/UML%20Diagram1.png)

# Classes:

1. Parser
   - Will take in a string and a tokenizer. It will return a vector of strings.
	``` C++
	class Parser
	{
	private:
		string Input;
		string Tokenizer;
	public:
		Parser(string input, string tokenizer);
		vector <string> parse();
	}
	```
2. Base
   - Will serve as an abstract base class for all functionality. The idea is to create and expression tree with the operators ADD, OR and SEMI
	``` C++
	class Base
	{
	public:
		virtual string evaluate() = 0;
	}
	```
3. Command
   - Will take in a vector of strings and comapre the first string to a list of predefined functions. If it exists, then it executes, if not it returns "No Such Command Exisits"
	``` C++
	class Commands
	{
	private:
		vector<string> input;
	public:
		Commands(vector<sting> input);
		string evaluate();
	}
	```
4. Operator
   - Will have three children classes: ADD, OR and SEMI
	``` C++
	class Operator
	{
	private:
		string OpString;
	public:
		Operator(string input);
		string evaluate();
	}
	```
5. Add
   - Will execute Command 2 if Command 1 executes properly
	``` C++
	class Add
	{
	private:
		Base* command1;
		Base* command2;
	public:
		Add();
		Add(Base* CMD1, Base* CMD2);
		string evaluate();
	}
	```
6. Or
   - Will execute Command 2 if Command 1 fails
	``` C++
	class Or
	{
	private:
		Base* command1;
		Base* command2;
	public:
		Or();
		Or(Base* CMD1, Base* CMD2);
		string evaluate();
	}
	```
7. Semi
   - Will execute Command 1 and Command 2, regardless of success or failiure
	``` C++
	class Semi
	{
	private:
		Base* command1;
		Base* command2;
	public:
		Semi();
		Semi(Base* CMD1, Base* CMD2);
		string evaluate();
	}
	```


# Prototypes/Research:

1. execvp will be used to run the commands 
2. fork will be used to run those multiple processes simultaneously
3. waitpid will put processes on hold to ensure they follow the guidelines of the connectors
4. The guidelines for the connectors are as follows:
   - And (&&): Will execute Command 2 IF Command 1 is successful
   - Or (||): Will execute command 2 IF Command 1 is unsuccessful
   - Semi (;) Will execute Command 1 AND Command 2 regardless of either's success 

# Development and Testing Roadmap:

1. [Parser](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/1)
2. [Parser unit testing](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/2)
3. [Base](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/3)
4. [Command](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/4)
5. [Command: evaluate()](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/5)
6. [single command integration testing](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/6)
7. [Operator class](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/7)
8. [Add: evaluate()](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/8)
9. [Or: evaluate()](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/9)
10. [Semi: evaluate()](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/10)
11. [Operator unit testing](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/11)
12. [multiple command integration testing](https://github.com/cs100/spring-2019-assignment-cs100-abdullah-emily/issues/12)
