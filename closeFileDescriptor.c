#include<stdio.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    printf("Close File Descriptor %d\n", getpid());
    close(STDOUT_FILENO);
    printf("File descriptor close\n");
    return 0;
}

//neither error will print nor the print statement because terminal file de
// scriptor is closed so nothing will be printed on terminal 