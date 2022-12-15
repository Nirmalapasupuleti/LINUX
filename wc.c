/*program to demonstrate our own version of wc command*/

//header file decleration
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include <fcntl.h>

//Declearing the command line
int main(int argc, char * argv[])
{
        if (argc < 2)
        {
                printf("give file name\n");
                return 0;
        }
//variable devleration  

        int fd, i=0;
        int c_ch=0, c_word=0, c_line=0;
        char buffer[100],data;
//file opened in read only mode 
        fd = open(argv[1] ,O_RDONLY);
//fd is less than zero it will print file cannot open   
        if(fd < 0)
        {
                perror("cannot open file");
                printf("errno:%d\n",errno);
                return -1;
        }
//this line for reading the data        
        while((data=read(fd,buffer,1))>0)
        {
//This is for printing the character            
                c_ch++;
                if(buffer[i] == ' ' || buffer[i] == '\n')
//printing the word/printing the line                   
                        c_word++;
                if( buffer[i] == '\n')
                        c_line++;
        }
//this line is for printing
        printf(" %d  %d %d %s\n",c_line,c_word,c_ch,argv[1]);
//closing the file      
        close(fd);
}
