// program for Zombie process
#include<stdio.h>
#include<unistd.h>
int main()
{
	//CHILD
	if(fork()==0)
	{
		//getting a id of chaild pid and parent ppid
		printf("in child pid=%d ppid=%d\n",getpid(),getppid());
		sleep(10);
		//After 10 seconds child will be termanating
		printf("child is terminating\n");
	}
	else
	{
		printf("in parent pid=%d ppid=%d\n",getpid(),getppid());
		while(1);
	}
}
