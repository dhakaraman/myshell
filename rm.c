#include <stdio.h>
#include <stdlib.h>
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

void rem(int argc, char *c[]){

	if(argc==1){
		printf("rm: missing operand");
		return;
	}

	if(strncmp(c[1],"-r",2)==0){
		DIR *dir =opendir(c[2]);
		if(dir){
			int result=rmdir(c[2]);
			if(result == 0){
				printf("Directory deleted successfully \n" );
			}
			else{
				printf("Error: unable to delete the folder\n");
			}
		}

	}
	else if(strncmp(c[1],"-i",2)==0){
		printf("Do you want to delete this file\n");
		char ans[100];
		scanf("%[^\n]%*c",ans);

		if (strcmp(ans,"y")==0 ||strcmp(ans,"Y")==0 )
		{
			DIR *dir =opendir(c[2]);
			if(dir){
				printf("%s It is a Directory\n",c[2]);
				closedir(dir);
			}
			else{
				if(remove(c[2]) == 0){
					printf("File deleted successfully \n" );
				}
				else{
					printf("Error: unable to delete the file\n");

				}
			}
		}

	}
	else{
		DIR *dir =opendir(c[1]);
		if(dir){
			printf("rm: cannot remove '%s': Is a directory\n",c[1]);
			closedir(dir);
		}
		else{
			if(remove(c[1]) == 0){
				printf("File deleted successfully \n" );
			}
			else{
				printf("Error: unable to delete the file\n");

			}
		}
	}
}

int main(int argc, char *argv[])
{
	rem(argc, argv);
	return 0;
}
