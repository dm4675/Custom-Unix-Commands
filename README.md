# Custom-Unix-Command-Uniq-Tail
XV6 Operating System compatible UNIX commands 'uniq' and 'tail' implementations/extensions.

UNIQ COMMAND

Part 1: Implementing the 'uniq' command.
'uniq' is a Unix utility which, when fed a text file, outputs the file with adjacent identical lines collapsed to one. If a filename is provided on the command line (i.e., uniq FILE) then 'uniq' will open it, read, filter out, print without repeated lines in this file, and then close it. If no filename is provided, 'uniq' will read from standard input

It can also be invoked without a file, and have it read from standard input. For example, a pipe(|) can be used to direct the output of another xv6 command into uniq.

Part 2: Extending the 'uniq' command. 
Implementation of the below two behaviors of UNIX 'uniq' utility :
• -c: count and group prefix lines by the number of occurrences 
• -d: only print duplicate lines


TAIL COMMAND

The traditional UNIX tail utility can print out lines from the end of a file. If the number of lines is not configured (i.e., tail FILE), tail would print out the last 10 lines of its input. Or we could trigger by calling tail -NUM FILE, for example tail -2 README to print the last 2 lines of the file README. 

This subpart is the custom implementation of the above. If a filename is provided on the command line then tail will open it, read and print the last NUM lines (no extra blank lines), and then close it. If no filename is provided, tail will read from standard input.

