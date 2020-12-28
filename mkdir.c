#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
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

void my_mkdir(int argc, char *c[]){

    if(argc==1){
        printf("mkdir: missing operand\n");
    }

    if(strcmp(c[1],"-v")==0){
        DIR* dir = opendir(c[2]);
        if(dir){
            printf("mkdir: cannot create directory ‘%s’: File exists\n",c[2]);
            closedir(dir);
        }
        else{
            mkdir(c[2], S_IRWXU);
            printf("mkdir: created directory '%s'\n",c[2]);
        }
    }


    else if(strcmp(c[1],"-m")==0){
    	int mode;

		if(c[2]==NULL){
			printf("mkdir: option requires an argument -- 'm'\n");
			return;
		}

		DIR* dir =opendir(c[3]);
		if(dir){
		    printf("Directory already exists\n");
		    closedir(dir);
		}
		else{

			if(strcmp(c[2],"a=x")==0)
		    	mode=0111;
		    else if(strcmp(c[2],"a=w")==0)
		    	mode=0222;
		    else if(strcmp(c[2],"a=wx")==0)
		    	mode=0333;
		    else if(strcmp(c[2],"a=r")==0)
		    	mode=0444;
		    else if(strcmp(c[2],"a=rx")==0)
		    	mode=0555;
		    else if(strcmp(c[2],"a=rw")==0)
		    	mode=0666;
		    else if(strcmp(c[2],"a=rwx")==0)
		    	mode=0777;
		    else{
		    	printf("Invalid mode\n");
		    	return;
		    }
		    mkdir(c[3],mode);
		    printf("Directory has been created \n");
		}
    }
    else{
        DIR* dir =opendir(c[1]);
        if(dir){
            printf("Directory already exists\n");
            closedir(dir);
        }
        else{
            mkdir(c[1], S_IRWXU);
        }
    }
}

int main(int argc, char *argv[])
{
    my_mkdir(argc, argv);
    return 0;
}
