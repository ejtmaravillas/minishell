# Minishell
_As beautiful as a shell_

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Mandatory Requirements](#mandatory-requirements)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Abstract Syntax Tree (AST)](#abstract-syntax-tree-ast)
- [Lexical Analysis](#lexical-analysis)
- [Built-in Commands](#built-in-commands)
- [Project Guidelines](#project-guidelines)
- [Acknowledgments](#acknowledgments)

---

## Introduction
Minishell is a simple UNIX shell implemented in C, designed to mimic the behavior of Bash. This project provides an opportunity to learn about processes, file descriptors, and fundamental operating system concepts. It's your very own little Bash, allowing you to explore the challenges faced in early shell development.

## Features
- Prompt display for user commands.
- Command execution via the PATH variable or direct paths.
- Support for single and double quotes.
- Redirection operators (`<`, `>`, `<<`, `>>`).
- Piping commands (`|`).
- Handling environment variables and exit status (`$`, `$?`).
- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`).
- Built-in commands like `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- Memory management with no leaks in user-implemented code.

## Mandatory Requirements
The following features are implemented as per the project specifications:
1. **Interactive Mode**:
   - `Ctrl-C`: Displays a new prompt.
   - `Ctrl-D`: Exits the shell.
   - `Ctrl-\`: Does nothing.
2. **Command Execution**:
   - Execute commands using relative or absolute paths.
   - Built-in commands for essential operations.
3. **Redirections**:
   - `<` for input redirection.
   - `>` for output redirection.
   - `<<` for heredoc input.
   - `>>` for appending output.
4. **Pipes**:
   - Chain commands with `|`.
5. **Environment Variables**:
   - Expand variables prefixed with `$`.
   - Support for `$?` to retrieve the last command's exit status.

## Getting Started
### Prerequisites
- GCC compiler with `-Wall -Wextra -Werror` flags enabled.
- Libft library (if applicable).

### Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd minishell

2. Compile the project using the Makefile:
   ```bash
   make
   ```

3. Run the shell:
   ```bash
   ./minishell
   ```  

## Usage
To use Minishell, follow these steps:

1. Run the shell executable:
   ```bash
   ./minishell


2. You will see a prompt appear where you can enter commands.

3. Supported commands and features include:

   **Command Execution:**
   - Run commands using absolute or relative paths
   - Execute binaries located in directories listed in the PATH environment variable

   **Redirections:**
   - `<` redirects input
   - `>` redirects output
   - `<<` reads input until a specific delimiter is seen (heredoc)
   - `>>` appends output to a file

   **Pipes:**
   - Use `|` to pipe the output of one command to another

   **Environment Variables:**
   - Use `$<var>` to access environment variables
   - `$?` contains the exit status of the last executed command

   **Signal Handling:**
   - `Ctrl-C`: Interrupts the current process and displays a new prompt
   - `Ctrl-D`: Exits the shell
   - `Ctrl-\`: Does nothing

4. Example commands:

   - Simple command:
     ```bash
     ls -l
     ```
   
   - Command with redirection:
     ```bash
     echo "Hello, World!" > output.txt
     ```
   
   - Command with pipes:
     ```bash
     cat file.txt | grep "keyword"
     ```
   
   - Command with environment variables:
     ```bash
     echo $HOME
     ```

5. To exit the shell, type:

    ```bash
     exit
     ```
    - Or press Ctrl-D.