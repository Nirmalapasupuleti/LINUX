/*program to demonstrate to write a cp command by using system calls*/

//Header file decleration
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
//initializing the command line argument
void main(int argc, char *argv[])
 {
	 //initializing the file
   int f1, f2;
   char buff[200];
   long int n;
//file open in read only mode
   f1=open(argv[1], O_RDONLY);

      if((f2=(read(f1,buff,200))!=EOF))
         
     
          printf("%s\n",buff);
             
}


