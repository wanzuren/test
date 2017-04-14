/*************************************************************************
	> Copyright (C), 2015, Enoch Robot Tech. Co., Ltd. 
	> File Name: main.c
	> Author: 
	> Description: 
	> Created Time: Wed 01 Mar 2017 11:55:03 AM CST
	> Modify: 
	> Date       Author        Description 
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char **argv)
{
    int fd;
    int val = 1;
    fd = open ("/dev/xyz", O_RDWR);
    if (fd < 0)
    {
        printf ("can't open!\n");
    }
    if (argc != 2)
    {
        printf ("Usage : \n");
        printf ("%s <on|off>\n", argv [0]);
        return 0;
    }
    if (strcmp (argv[1], "on") == 0)
    {
        val = 1;
    }
    else
    {
        val = 0;
    }
    write (fd, &val, 4);
    return 0;
}
