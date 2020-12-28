# Simple Shell In C <br />

This is a simple shell which handles 10 commands, 5 internal and 5 external. This handles a simple command and at most two flags.<br />

INTERNAL COMMANDS <br />
&nbsp;&nbsp;&nbsp;&nbsp;    1. cd command: <br />
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; options : cd <filename> <br />
			      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; cd<br />
			      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; cd ..<br />
			      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; cd ~<br />
			      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; cd –P <filename><br />
			      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; cd –L <filename><br />
&nbsp;&nbsp;&nbsp;&nbsp; Error handling: 1). Invalid path prompt when directories are not available.<br />
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2). Invalid option prompt when wrong flag is entered.
    &nbsp;&nbsp;&nbsp;&nbsp;2. echo command:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;options:  echo <string>
		     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo –n <string>
		     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo –E <string>
	&nbsp;&nbsp;&nbsp;&nbsp;Assumptions: Only supports –n,-E and simple echo commands.

&nbsp;&nbsp;&nbsp;&nbsp;    3.  history command:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;options : history
	    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; history <integer number>
	    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; history –c
&nbsp;&nbsp;&nbsp;&nbsp; error handling: invalid command if invalid command is passed followed by history.
&nbsp;&nbsp;&nbsp;&nbsp; Assumptions: Positive integers should be passed.
	&nbsp;&nbsp;&nbsp;&nbsp;This command will print the entire history when the simple history command is entered. Is history followed by an integer then last n command will be printed. To clear the history you just need to type history –c.

 &nbsp;&nbsp;&nbsp;&nbsp;   4. pwd command :
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;options: pwd
	   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  pwd –P
	   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  pwd – L
&nbsp;&nbsp;&nbsp;&nbsp;Error handling: 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Invalid command if command passed is other than the given options.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It prints the current working directory.
 &nbsp;&nbsp;&nbsp;&nbsp;   5. exit command: 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;options: exit
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;It will terminate the process and exit he shell.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;EXTERNAL COMMANDS

&nbsp;&nbsp;&nbsp;&nbsp;   1.  ls command:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;options: ls
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   ls –m
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ls -1
ls command prints the files and folders in the current working directory. The –m flag prints the separated with coma and the –1 flag print the files and folders one per line.

&nbsp;&nbsp;&nbsp;&nbsp;2 mkdir command: 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Options: mkdir <directory name> It creates new directory and give an error if not possible to make a directory.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mkdir -v <directoryname> It creates a directory and give a message of successful completion and give and error if not possible.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mkdir -m <file mode> <directoryname> It creates a file with the given mode in the command and give error if not possible
&nbsp;&nbsp;&nbsp;&nbsp;3 rm command: 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Options:
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;rm <filename> deletes the file and give error if not possible.
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;rm -i <filename> ask user before deleting the file and give an error if not possible.
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;rm -r <directoryname> delete directory and give an error if not possible

    &nbsp;&nbsp;&nbsp;&nbsp;4.  Date command
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Options: date displays the date in IST formate
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;date -R displays the date in gmt +0530
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;date –I dispalys the date in yyyy-mm-dd format  
   &nbsp;&nbsp;&nbsp;&nbsp; 5. Cate command:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Options:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cat <filename>prints the content of the file.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cat -E <filename> display $ at end of each line.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cat –n <filename> displays number of the all lines of the file

