/* program to demonstrate copy command by using system call*/
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv)
{
        if (argc < 3)
        {
                printf("give file name\n");
                        return 0;
        }
        //in that i decleared source file and destination file
        int fs, fd, data;
        //Declearing the buffer
                char buffer[100];
                //opened sourse file in readonly mode
                fs = open(argv[1] ,O_RDONLY);
                //opened destination file into write mode
                fd = open(argv[2] ,O_WRONLY | O_CREAT,0777);
                if(fs < 0)
                {
                        perror("cannot open file");
                                printf("errno:%d\n",errno);
                                return -1;
                }
        while((data = read(fs,buffer,1))>0)
        {
                //write the data into destination file
                write(fd,buffer,1);
        }
        //this line for closing the files
        close(fs);
        close(fd);
}


