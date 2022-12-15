/*program to demonstrate our own du command*/

//Header file decleration
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

 
//command line argument
int main(int argc, char const *argv[])
{
//initializing the variables	
    int fd1 ; 
    float fd2 , ret ;
    struct stat statbuf;
    ret = stat(argv[1],&statbuf);
    //st_blksize block size for filesystem I/O
    fd2 = (statbuf.st_blksize);
    //Number of 512B blocks allocated
    printf("%ld\t %s\n",statbuf.st_blocks/2, argv[1]);
    return 0;
}
