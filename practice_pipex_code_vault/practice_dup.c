#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char ** argv, char ** envv)
{
    int pid = fork();
    if (pid == -1)
    {
        return(1);
    }
    if (pid == 0)
    {
        int file_fd = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if (file_fd == -1)
        {
            return(3);
        }
        printf("The fd to ping results: %d\n", file_fd);
        //int new_file_fd = dup(file_fd);// creates another fd that points to the file pingResults
        int new_file_fd = dup2(file_fd,STDOUT_FILENO);//fd that we want to clone,valuw we want a new fd actually have
        printf("The duplicated fd: %d\n", new_file_fd);
        close(file_fd);
        int err = execlp("ping", "ping","-c", "1","google.com", NULL);
        if (err == -1)
        {
            printf("Could not find function to execute\n");
            return(4);
        }
    }
    else{
        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {// if it returns true (!= 0), the programm terminated normally
            int statusCode = WEXITSTATUS(wstatus);
            //return value inside the main , the value it exited with, using the exit call
            if(statusCode == 0)
                printf("Success!\n");
            else
                printf("Failure with statusCode %d\n", statusCode);
        
        }
    
        printf("Post processing\n");
    }
    return(0);

}
