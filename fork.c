#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("hello this is fork example (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } 
    else if (rc == 0) {
        // child (new process)
        printf("fork example child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("fork example parent of %d (pid:%d)\n",
        rc, (int) getpid());
    }

    return 0;
}

