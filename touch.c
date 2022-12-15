/*program to demonstrate our own version of touch command*/

//including header file
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
//passing a command line argument
int main(int argc,char **argv)
{
	
        if(argc<2)
        {
                printf("please provide the name:\n");
                return 0;
        }
        int touch,i;
        for(int i=0;i<argc;i++)
        {
		//this will create the empty file 
                touch=open(argv[i],O_CREAT);
		//If it is less than zero it will print file not opened
                                if(touch< 0)
                                {
                        printf("file not opened");
                                }
                }
        return 1;
}

