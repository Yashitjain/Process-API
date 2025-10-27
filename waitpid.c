#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child (new process)
        printf("child (pid:%d)\n", (int) getpid());
    } else
    {   
        int status;
        int wc = waitpid(rc, &status, 0);
        printf("parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
        /* code */
    }
    
    return 0;
}
