#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

char * filenameget (char * path)
{
	char * buff;
  	buff = path+strlen(path);
  	while(*buff!='/' && buff>=path){
    		buff--;
  	}
  	buff+=1;

  	return buff;
}


void
ls(char *path)
{
 int fd;
	fd =open (path,0);
	if (fd<0)
	{
		printf(1,"cannot open path: %s\n", path);
		return;
	}
	struct stat file_status;
	if (fstat(fd, &file_status))
	{
		printf(1,"cannot stat path: %s\n", path);
		return;
	}
	if(file_status.type !=T_DIR )
	{
	printf(1,"%s\n", filenameget(path));

	}
	else 
	{
		struct dirent search;
		while (read(fd, &search, sizeof(search)) == sizeof(search))
		{
			if (search.inum ==0) continue;
			printf(1,"%s\n", search.name);
		}
	}
	close(fd);
	return;
}

int main(int argc, char *argv[])
{
    int i;

    if(argc < 2){
        ls(".");
        exit();
    }
    for(i=1; i<argc; i++)
        ls(argv[i]);
    exit();
}
