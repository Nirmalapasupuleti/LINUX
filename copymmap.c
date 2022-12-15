//Write an LINUX System Programming copy one file content to anothe file using mmap() system call
#include<stdio.h>
#include<stdlib.h>//It has a information related a input/output and memory
#include<sys/mman.h>
//for creating and reading a file
#include<fcntl.h>
//which give information about the file and file system 
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char *argv[]){

	int sfd, dfd,i;
	char *src, *dest;
	struct stat s;

	/* SOURCE */
	sfd = open(argv[1], O_RDONLY);
	fstat(sfd, &s); // st_size = blocksize
    
	printf("%ld\n",s.st_size);
       //s.st_size It give the size of the file
       //PROT_READ the memory can be read MAP_PRIVATE the mapping will not be
	src = mmap(NULL,1, PROT_READ, MAP_PRIVATE, sfd, 0);

	/* DESTINATION */
	dfd = open(argv[2], O_RDWR | O_CREAT, 0666);

//	ftruncate(dfd, s.st_size);

	dest = mmap(NULL,1, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);

	/* COPY */
        int size = lseek(sfd,0,SEEK_END);
	//memcpy(src, dest, s.st_size);
	for(int i=0;i<size ;i++)
		{
		 write(dfd,&src[i], 1);
		//printf("%s",src);
		//dfd[i]=src[i];
               }
	//munmap(src, s.st_size);
	//munmap(dest, s.st_size);

	close(sfd);
	close(dfd);

	return 0;
}

