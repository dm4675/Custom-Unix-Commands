# Custom-Unix-Commands
XV6 Operating System compatible UNIX command 'uniq' implementation/extension.

Part 1: Implementing the 'uniq' command.
'uniq' is a Unix utility which, when fed a text file, outputs the file with adjacent identical lines collapsed to one. If a filename is provided on the command line (i.e., uniq FILE) then 'uniq' will open it, read, filter out, print without repeated lines in this file, and then close it. If no filename is provided, 'uniq' will read from standard input

It can also be invoked without a file, and have it read from standard input. For example, a pipe(|) can be used to direct the output of another xv6 command into uniq.

Part 2: Extending the 'uniq' command. 
Implementation of the below two behaviors of UNIX 'uniq' utility :
• -c: count and group prefix lines by the number of occurrences 
• -d: only print duplicate lines
