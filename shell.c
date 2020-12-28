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


void welcome()
{
static int flag = 1;
if (flag==1) {

	const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	flag = 0;
	printf("******************"
        "****************************");
    printf("\n\t\t****MY SHELL****");
    printf("\n*******************"
        "***************************\n");
	}
	printf(">>>");

}


int main( ){

	char line[100];
	int count=0;
	char history[10000][100];
	char cur_dir[100];
	getcwd(cur_dir,sizeof(cur_dir));

	while (1){

		welcome();
		scanf("%[^\n]%*c",line);

		strcpy(history[count],line);
		count++;

		if(line==NULL){
			break;
		}

		char envp[100];
		strcpy(envp,cur_dir);

		int command_check=0;

		char *present_dir;
		char curr_path[100];
		char buff[1000];

		char *tkn=NULL;
		tkn=strtok(line," ");

		char *array[100];
		int i=0;
		int len=0;

		while(tkn !=NULL){
			array[i] = (char *) malloc(strlen(tkn)+1);
			strcpy(array[i],tkn);
			tkn=strtok(NULL," ");
			i++;
			len++;
		}

		array[i]=NULL;

		if(strncmp(array[0],"exit",4)==0){
			break;
		}
		else if(strncmp(array[0],"cd",2)==0){
			command_check=1;
			if(array[1]==NULL || strcmp(array[1],"~")==0){
				chdir("/home/aman");
			}
			else if(strncmp(array[1],"-P",2)==0 || strncmp(array[1],"-L",2)==0){
				int check=chdir(array[2]);
				present_dir=getcwd(buff,sizeof(buff));
				if(check==-1){
					printf("Invalid path\n");
				}
			}
			else if(array[2]!=NULL){
				printf("No such option\n");
			}
			else{
				int check=chdir(array[1]);
				present_dir=getcwd(buff,sizeof(buff));
				if(check==-1){
					printf("Invalid path\n");
				}
			}
		}
		else if(strncmp(array[0],"pwd",3)==0){
			command_check=1;
			if(array[1]==NULL){
				getcwd(curr_path,sizeof(curr_path));
				printf("%s\n", curr_path);
			}
			else if(strncmp(array[1],"-P",2)==0){
				getcwd(curr_path,sizeof(curr_path));
				printf("%s\n", curr_path);
			}
			else if(strncmp(array[1],"-L",2)==0){
				getcwd(curr_path,sizeof(curr_path));
				printf("%s\n", curr_path);
			}
			else{
				printf("Invalid command\n");
			}

		}
		else if(strncmp(array[0],"history",6)==0){
			command_check=1;

			if(array[1]==NULL)
			{
				for (int x = 0;x<count;x++){
					printf("%d  %s\n",x+1, history[x]);
				}
			}
			else if(strcmp(array[1],"-c")==0){
				count=0;
			}
			else{
				int num = atoi(array[1]);
				int tt=1;
				if(num>0){
					for(int x=count-num;x<count;x++){
						printf("%d %s\n",x+1,history[x]);
					}
				}
				else{
					printf("Invalid command\n");
				}
			}
		}
		else if(strncmp(array[0],"echo",4)==0){

			command_check=1;
			if(array[1]==NULL){
				printf("\n");
			}
			else if(strcmp(array[1],"-n")==0){
				for(int x=2;x<len;x++){
					printf("%s ",array[x]);
				}
			}
			else if(strcmp(array[1],"-E")==0){
				for(int x=1;x<len;x++){
					printf("%s",array[x]);
				}
				printf("\n");
			}
			else{
				for(int x=1;x<len;x++){
					printf("%s ",array[x]);
				}
				printf("\n");
			}

		}

		if(fork()!=0){
			wait(NULL);
		}

		else {

			if(strncmp(array[0],"ls",2)==0){
				strcat(envp,"/ls.o");
				execv(envp,array);

			}

			else if(strncmp(array[0],"cat",3)==0){
				strcat(envp,"/cat.o");
				execv(envp,array);
			}

			else if(strncmp(array[0],"rm",2)==0){
				if(array[1]==NULL){
					printf("rm: missing operand\n");
				}
				else{
					strcat(envp,"/rm.o");
					execv(envp,array);
				}
			}

			else if(strncmp(array[0],"date",4)==0){
				strcat(envp,"/date.o");
				execv(envp,array);
			}

			else if(strncmp(array[0],"mkdir",5)==0){
				strcat(envp,"/mkdir.o");
				execv(envp,array);
			}
			else {
				if(command_check==0){
					printf("Command not found\n");
				}
			}
			exit(0);
		}

	}
	return 0;
}
