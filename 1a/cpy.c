#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char buffer[2048];
void copy(int old, int new)
{
    int count;
    while ((count= read(old, buffer, sizeof(buffer))) > 0)
        write(new, buffer, count);
}
int main(int argc, char *argv[])
{
    int fdold,fdnew;
    if (argc!=3)
    {
        printf("\n Need 2 arguments for copy program: \n");
        exit(1);
    }
    fdold= open(argv[1], O_RDONLY);
    if (fdold==-1)
    {
        printf("\n Cannot open file %s", argv[1]);
        exit(1);
    }
    fdnew = creat(argv[2], 0666);
    if (fdnew==-1)
    {
        printf("\nCannot create file %s", argv[2]);
        exit(1);
    }
    copy(fdold,fdnew);
    return 0;
}