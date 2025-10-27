#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    printf("Fork And File %d\n", getpid());
    int fd = open("/home/yashit/test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }
    else if (rc == 0){
        //Child Process
        printf("Child Process %d writing to file\n", getpid());
        // dprintf(fd, "This is Child Process  %d\n", getpid());
        for(int i = 0; i < 100 ; i++){
            dprintf(fd, "This is Child Process  %d line %d\n", getpid(), i);
        }
        printf("child process descriptor %d\n", fd);
    }
    else{
        //Parent Process
        printf("Parent Process %d writing to file\n", getpid());
        // dprintf(fd, "This is Parent Process  %d having child %d\n", getpid(), rc);
        for(int i = 0; i < 100 ; i++){
            dprintf(fd, "This is parent Process  %d line %d\n", getpid(), i);
        }
        printf("parent process descriptor %d\n", fd);
    
    }
    return 0;
}
