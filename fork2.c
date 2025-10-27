#include <stdio.h>
#include <unistd.h>

int main() {
    printf("hello (pid:%d)\n", (int) getpid());
    int x = 10;
    int rc = fork();

    if(rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        return 1;
    } 
    else if (rc == 0) {
        // child (new process)
        x += 10;
        printf("parent (pid:%d) child (pid:%d) x: %d\n", (int) getpid(), rc, x);
    } else {
        // parent goes down this path (main)
        x -= 5;
        printf("parent (pid:%d) child (pid:%d) x: %d\n", (int) getpid(), rc, x);

    }

    return 0;
}

