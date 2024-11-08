# Pipex - A Pipe Implementation in C

**Pipex** is a C project focused on handling pipes and executing shell commands through pipes. The goal is to simulate the behavior of a shell command that processes input and output between multiple programs using pipes.

## Project Description

In this project, I implemented a program that mimics the behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

The program takes four arguments:
1. **file1**: The input file.
2. **cmd1**: The first command to be executed.
3. **cmd2**: The second command to be executed.
4. **file2**: The output file.

The program processes the content of **file1**, applies **cmd1**, passes the result through a pipe to **cmd2**, and writes the output to **file2**.

## Functionality Implemented

The program supports the following behavior:

```bash
./pipex infile "ls -l" "wc -l" outfile
```
This behaves like:
```bash
< infile ls -l | wc -l > outfile
```

## Bonus Part:
The program also supports handling `multiple pipes` and `here_doc` functionality.

### Example with Multiple Pipes:
```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

This behaves like:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

### Example with here_doc:
```bash
./pipex here_doc LIMITER cmd cmd1 file
```
This behaves like:
```bash
cmd << LIMITER | cmd1 >> file
```

## Notes
- The project was developed with proper error handling to ensure no unexpected behavior or crashes.
- It supports piping between two or more commands and handling files through the pipe mechanism.
- The bonus features include handling multiple pipes and the here_doc functionality.

## License

This project is subject to the 42 School's License.



