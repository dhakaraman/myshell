#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>

void cat(int argc, char *c[]){
	FILE *fp;

	if(argc == 1){
		printf("rm: missing operand\n");
	}

	if(strncmp(c[1],"-E",2)==0){

		fp =fopen(c[2],"r");
		if( fp == NULL){
			perror("Error:");
		}
		else{
			char line[200];
			fgets(line,1024,fp);
			int count=1;
			rewind(fp);
			while (fgets(line,200,(FILE*)fp)!=NULL){
				printf("%s$",line );
			}
			fclose(fp);
		}

	}
	else if(strncmp(c[1],"-n",2)==0){

		fp =fopen(c[2],"r");
		if( fp == NULL){
			perror("Error:");
		}
		else{
			char line[200];
			fgets(line,1024,fp);
			int count=1;
			rewind(fp);
			while (fgets(line,200,(FILE*)fp)!=NULL){
				printf("%d %s",count++,line );
			}
			fclose(fp);
		}

	}


	else{

		fp =fopen(c[1],"r");
		if( fp == NULL){
			perror("Error:");
		}
		else{
			char line[200];
			fgets(line,1024,fp);

			rewind(fp);
			while (fgets(line,200,(FILE*)fp)!=NULL){
				printf("%s",line );
			}
			fclose(fp);
		}
	}
}

int main(int argc, char *argv[])
{
	cat(argc, argv);
	return 0;
}
