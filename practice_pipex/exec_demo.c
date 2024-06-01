#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

// l - lists of arguments
// p - path
// v - vector
// e - environment - a set of variables that can be passed

int main(int argc, char *argv[], char *envp[])
{
    //   1)        int execvp (const char *file, char *const argv[]);
    //char *args[] = {"./EXEC", NULL};
    // char *args[] = {"wc", "my_file.txt", "-l", NULL};
    //char *args[] = {"ls", "-l", NULL};
    //execvp(args[0], args);

    //   2)        int execv(const char *path, char *const argv[]);
    /*char * args[] = {"./EXEC", NULL};
    execv(args[0],args);*/

    //   3)        int execl(const char *path, const char *arg,.../* (char  *) NULL */);
    /*execl("./EXEC", "./EXEC", NULL);*/
    //execl(".././EXEC", ".././EXEC", NULL); 
    //execl("/usr/bin/wc", "/usr/bin/wc", "my_file.txt", NULL);
    //execl("/usr/bin/ls", "/usr/bin/ls", "-al", NULL);
    //execl("/usr/bin/ping", "/usr/bin/ping", "google.com", NULL);


    //   4)        int execlp(const char *file, const char *arg,.../* (char  *) NULL */);
    /*according to the codeVault video it should work,
    because p - stands for the PATH and the command should be found from environment*/
    //execlp("./EXEC", "./EXEC", NULL); // does not work
    //execlp("wc", "wc", "-l", NULL); //  does not work, there is nothing to count!
    //execlp("wc", "wc", "my_file.txt", NULL); // wprks
    //execlp("ls", "ls", "-al", NULL);   //  WORKS!!!
    //execlp("ping", "ping", "google.com", NULL);
    

    //   5)        int execvpe(const char *file, char *const argv[],char *const envp[]);
    //   6)        int execlpe(const char *file, const char *arg, ..., char *const envp[]);
    //      5 and 6 are not available in my version of linux.
    char * args[] = {"/usr/bin/ping", "google.com", NULL};
    char * env[] = {"TEST=environment variable", NULL};
    execve(args[0], args, envp);

    int err = errno;
    printf("err = %d\n", err);

    //   6)        int execle(const char *path, const char *arg, .../*, (char *) NULL, char * const envp[] */);

    //   7)        int execve(cinst char *pathname, char *const argv[], char *const envp[]);
    printf("Ending-----");
    return(0);
}