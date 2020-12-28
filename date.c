#include <time.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>

void Date(int argc, char *c[]){
	time_t T;
	struct tm *tm;
	time(&T);
	tm=localtime(&T);
	char line[100];

	if(argc==1){
		strftime(line,100,"%a %b %d %X %Z %Y ", tm);
		printf("%s\n", line);
		return;
	}
	if (strcmp(c[1],"-R")==0){
		strftime(line,100,"%a, %d %b %Y %X %Z ", tm);
		printf("%s +0530\n", line);
	}

	else if(strcmp(c[1],"-I")==0){
		strftime(line,100,"%Y-%m-%d ", tm);
		printf("%s\n", line);
	}

	else{
		printf("No such command found");
	}

}

int main(int argc, char *argv[])
{
	Date(argc, argv);
	return 0;
}
