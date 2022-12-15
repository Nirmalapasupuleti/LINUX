/*program to demonstrate nice command*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//header decleration for getpriority and setpriority
#include <sys/resource.h>

 

int main()
{
//It returns the highest priority(lowest numerical value)//	
    int priority = getpriority(PRIO_PROCESS, 13094);
    printf("priority:%d\n", priority);
// sets the priorities os all of the specified processes to the specified value   
    int ret = setpriority(PRIO_PROCESS, 13094, -20);
    if (ret == 0)
    {
        printf("priority is set");
    }
    else 
    {
        printf("not set");
    }
}
