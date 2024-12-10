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

## Abstract Syntax Tree (AST)
The **Abstract Syntax Tree (AST)** is a core part of Minishell's functionality. It represents the hierarchical structure of commands, arguments, and operators parsed from the user's input. The AST simplifies the execution process by breaking down complex commands into manageable components.

### Key Features of the AST
- **Node Structure**:
  - Each node in the AST represents a distinct component, such as a command, an operator (`|`, `&&`, `||`), or a redirection (`<`, `>`, `<<`, `>>`).
  - Nodes store metadata, such as command arguments, file paths for redirections, or the type of operation.

- **Construction**:
  - The AST is built during the parsing phase after lexical analysis.
  - Parsing ensures correct precedence and associativity of operators, enabling commands like:
    ```bash
    echo "Hello" && ls | grep minishell > output.txt
    ```
    to be structured and executed correctly.

- **Traversal and Execution**:
  - Minishell traverses the AST in a post-order or pre-order fashion, depending on the operation.
  - Traversal enables proper handling of:
    - Piped commands (`|`).
    - Logical operators (`&&`, `||`).
    - Command execution with redirections.

### Benefits of Using an AST
- **Modularity**:
  - Commands are parsed into logical units, making it easier to handle individual components like redirections, pipes, and arguments.
- **Error Handling**:
  - The AST simplifies detecting and reporting syntax errors (e.g., unbalanced parentheses or invalid operator usage).
- **Scalability**:
  - The hierarchical structure allows for future extensions, such as adding more complex command handling or features.

The AST is crucial in transforming raw user input into a structured format that Minishell can execute efficiently and effectively.

## Lexical Analysis
**Lexical Analysis** is the initial phase in processing user input in Minishell. This step breaks down the input into meaningful components called tokens, which are then used to construct the Abstract Syntax Tree (AST) and execute commands.

### Key Steps in Lexical Analysis
1. **Tokenization**:
   - The input string is split into individual tokens based on separators like spaces, pipes (`|`), and redirection operators (`<`, `>`, `<<`, `>>`).
   - Example:
     ```bash
     echo "Hello, World!" > output.txt | grep "World"
     ```
     Tokenized as:
     ```
     [echo], ["Hello, World!"], [>], [output.txt], [|], [grep], ["World"]
     ```

2. **Character Classification**:
   - Each character is classified to determine its role:
     - Alphanumeric characters form part of a word or argument.
     - Special characters (`|`, `>`, `<`, `$`, `;`) are treated as operators.
     - Whitespace separates tokens but is ignored otherwise.

3. **Handling Quotes**:
   - Single quotes (`'`) prevent interpretation of special characters, treating everything inside as a literal string.
     - Example: `'Hello $USER'` is treated as `Hello $USER`.
   - Double quotes (`"`) preserve spaces but allow variable expansion for `$` and backslashes (`\`).
     - Example: `"Hello $USER"` expands `$USER`.

4. **Error Detection**:
   - Detect and handle common errors:
     - Unclosed quotes.
     - Invalid token sequences (e.g., `| |` or `>> <`).

5. **Environment Variables**:
   - Replace `$<variable>` with its corresponding value from the environment.
     - Example:
       ```bash
       echo $HOME
       ```
       Expands `$HOME` to its value (e.g., `/home/user`).

6. **Output**:
   - Produce a list of tokens for further processing by the parser and AST generator.

### Example of Lexical Analysis
Input:
```bash
ls -l | grep minishell > result.txt
```

Output:
```bash
[
  {type: "COMMAND", value: "ls"},
  {type: "OPTION", value: "-l"},
  {type: "PIPE", value: "|"},
  {type: "COMMAND", value: "grep"},
  {type: "ARGUMENT", value: "minishell"},
  {type: "REDIRECTION", value: ">"},
  {type: "FILENAME", value: "result.txt"}
]

```
### Benefits of Lexical Analysis

- **Efficiency:**
  - Converts complex input into manageable tokens for parsing.

- **Error Prevention:**
  - Detects syntax errors early in the command processing pipeline.

- **Flexibility:**
  - Ensures compatibility with various input patterns and command structures.

Lexical Analysis lays the foundation for parsing and execution, ensuring that Minishell can interpret and process user commands accurately.

## Built-in Commands
Minishell includes several built-in commands to handle basic shell functionalities. These commands are implemented internally, bypassing the need for external binaries.

### Supported Built-ins
1. **echo [-n] [text]**
   - Prints the given text to the standard output.
   - Option `-n` prevents a newline character from being added.
   - Example:
     ```bash
     echo "Hello, World!"
     echo -n "No newline"
     ```

2. **cd [path]**
   - Changes the current working directory to the specified path.
   - Example:
     ```bash
     cd /home/user
     cd ..
     ```

3. **pwd**
   - Prints the current working directory.
   - Example:
     ```bash
     pwd
     ```

4. **export [var=value]**
   - Adds or modifies environment variables.
   - Example:
     ```bash
     export PATH="/usr/local/bin:$PATH"
     ```

5. **unset [var]**
   - Removes an environment variable.
   - Example:
     ```bash
     unset PATH
     ```

6. **env**
   - Displays all current environment variables.
   - Example:
     ```bash
     env
     ```

7. **exit [status]**
   - Exits the shell with the specified status code (default is `0`).
   - Example:
     ```bash
     exit
     exit 1
     ```

These built-ins provide essential functionality for navigating and managing the shell environment.

## Project Guidelines
The Minishell project adheres to strict coding standards and guidelines to ensure high-quality implementation.

### General Rules
- **Language**: The project is written in C.
- **Norm Compliance**: All code follows the 42 Norm standards. Any norm error will result in a failing grade.
- **Error Handling**: Functions must not crash due to segmentation faults, bus errors, or double frees. Any such errors will result in a failing grade.
- **Memory Management**:
  - All dynamically allocated memory must be properly freed.
  - Memory leaks from your code are not allowed (excluding issues caused by `readline`).
- **Makefile**:
  - Includes rules: `NAME`, `all`, `clean`, `fclean`, `re`.
  - Must not relink files unnecessarily.
- **External Functions**:
  - Allowed functions include:
    - `readline`, `malloc`, `free`, `write`, `fork`, `pipe`, `dup`, `execve`, `wait`, `exit`, `getenv`, etc.
  - For a full list of allowed functions, refer to the project specifications.

### Bonus Rules
- Bonuses will only be evaluated if the mandatory part is implemented perfectly.
- Bonus features include:
  - Logical operators (`&&` and `||`) with parenthesis for precedence.
  - Wildcards (`*`) for file matching in the current directory.

Following these guidelines ensures your Minishel

## Acknowledgments
This project is part of the curriculum at [42](https://www.42.fr/), a coding school focused on peer-to-peer learning and project-based development. 

Special thanks to:
- The 42 Abu Dhabi (https://42abudhabi.ae/) community for its support and collaboration.
- Peers and evaluators who provided feedback and insights.
- The developers of `bash` for inspiring this project.

---

Happy coding and enjoy building your shell!
