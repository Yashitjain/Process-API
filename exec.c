#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child (new process)
        printf("child (pid:%d)\n", (int) getpid());
        char *myargs[2];
        myargs[0] = strdup("wc"); // program: "wc" //this wc is for the program to name itself
        myargs[1] = strdup("exec.c"); // arg: input file    
        myargs[2] = NULL; // mark end of array
        int res = execv("/bin/wc", myargs); // runs word count   
        printf("this shouldn’t print out | status : %d\n", res);
    } else { // parent goes down this path
        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n",
        rc, rc_wait, (int) getpid());
    }
    return 0;
 }
