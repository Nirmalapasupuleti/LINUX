
//3)WAP your own version of cat command using mmap system call
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("given the file name which file you want to map\n");
		return 0;
	}
	int fd;
	char * file;
	//It will give information about the file pointed to by pathname
	struct stat s;
	fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		printf(" file open fails\n");
		return -1;
	}
	//which information is to be retrived is specified by the fd    
	fstat(fd,&s);
	file= mmap(0,1,PROT_READ,MAP_SHARED,fd, 0);
	for(int i = 0;i<s.st_size;i++)
	{
		printf("%c",file[i]);
	}
	close(fd);
	return 0;
}
