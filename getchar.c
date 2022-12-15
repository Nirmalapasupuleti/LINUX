#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<stdio.h>
int main(int argc,char **argv[])
{
    //Hear I decleared fd
    int fd;

    char buffer[80];
    //Hear I menction read system call and write system call
            fd=read(0,buffer,80);
            fd=write(0,buffer,6);
            printf("\n");
    return 0;

}

