//Write a program to read framebuffer fixed size information?
#include<stdio.h>
#include<fcntl.h>
#include<linux/input.h>
//To control and to get Device specific parameters use ioctl
#include<sys/ioctl.h>
//Frame buffer library
#include<linux/fb.h>
int main(int argc, char *argv[])
{
    int fd1;
    
    fd1 = open (argv[1], O_RDONLY);
    if(fd1 < 3)
    {
        printf("Open Fails");
        return -1;
    }

 
// Hear I declear a screen info 
    struct fb_var_screeninfo varInfo;
// Get the variable screen info from the fram:           
    ioctl(fd1, FBIOGET_VSCREENINFO,&varInfo);
    
    printf("visiable res %u\n", varInfo.xres);
    printf("visiable res %u\n", varInfo.yres);
    printf("bits per pixel %u\n", varInfo.bits_per_pixel);
    
    return 0;
}
