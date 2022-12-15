/*program to demonstrate to echo command*/

//header file decleration
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//command line argument
int main(int argc,char**argv)

{
	//variable decleration
	int i,fd;

	for(i=1;i<argc;i++)
	{
		//This line is for printing the data what ever we enter
		write(fd,argv[i],strlen(argv[i]));

		write(1," ",2);
		printf("\n");
	}
}



