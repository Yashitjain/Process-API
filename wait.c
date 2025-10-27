#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    printf("Hello This is Wait System Call in OS %d\n", getpid());
    int rc = fork();

    if(rc < 0){
        printf("Child process failed %d\n", getpid());
    }
    else if (rc == 0){
        printf("This is a child process %d\n", getpid());
    }
    else{
        int wc = wait(NULL);
        printf("This is a parent process %d having child %d\n", getpid(), rc);
        printf("Wait returned %d\n", wc);
    }

    
    return 0;
}
