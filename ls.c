#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
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



void ls(int argc, char *cmd[]){


	struct dirent *de;
	DIR *dr = opendir(".");

	if(dr==NULL){
		printf("Could not open current directory\n");
	}

	if(argc==1){
		if(dr!= NULL){
			while((de= readdir(dr)) != NULL){
				if(!(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0)){
					printf("%s  ",de->d_name );
				}
			}
			printf("\n");
		}
		closedir(dr);
	}

	if(strncmp(cmd[1],"-m",2)==0){
		if(dr!= NULL){
			while((de= readdir(dr)) != NULL){
				if(!(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0)){
					printf("%s,\t",de->d_name );
				}
			}
			printf("\n");
		}
		closedir(dr);
	}
	else if(strncmp(cmd[1],"-1",2)==0){
		if(dr!= NULL){
			while((de= readdir(dr)) != NULL){
				if(!(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0)){
					printf("%s\n",de->d_name );
				}
			}
			printf("\n");
		}
		closedir(dr);
	}
	else{
		printf("ls: cannot access '%s': No such file or directory\n",cmd[1]);
	}

}

int main(int argc, char  *argv[])
{
	ls(argc,argv);
	return 0;
}
