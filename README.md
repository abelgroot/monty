Monty Interpreter

Description

Monty is a simple stack-based, bytecode interpreter that reads and executes Monty bytecode files. These files contain a series of opcodes that instruct the interpreter to manipulate a stack or queue. The project aims to implement a Monty bytecode interpreter in C, allowing for the execution of Monty 0.98 bytecode.

Monty is similar to assembly language, with each line consisting of an instruction (opcode) and an optional argument. The interpreter supports operations such as pushing values onto the stack, printing values, and more.

Project Requirements

    •	All files are compiled using gcc with the following options:

gcc -Wall -Werror -Wextra -pedantic -std=c89 \*.c -o monty
• Your code must adhere to the Betty style.
• You are allowed to use the C Standard Library.
• All your header files should be include-guarded.
• Use of global variables is restricted to one.

Usage

To use the Monty interpreter, pass the path of a Monty bytecode file as an argument to the program:
./monty <file>

Where <file> is the path to the file containing Monty bytecode instructions. Each line in the file contains an opcode (and, in some cases, an argument).

Authors

This project was implemented by the following contributors:

    •	[Abel Mulugeta] - https://github.com/abelgroot/monty
