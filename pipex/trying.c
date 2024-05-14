#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <file_to_list> <output_file>\n", argv[0]);
        return 1;
    }
    
    char *path_ls = "/bin/ls"; // Path to ls command
    char *ls_args[] = {path_ls, argv[1], NULL}; // ls command arguments
    char *ls_env[] = {NULL}; // Environment variables
    
    // Open output file
    FILE *output_file = fopen(argv[3], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }
    
    // Create pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    
    // Create child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) { // Child process
        // Redirect stdout to write end of pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]); // Close read end of pipe
        
        // Execute ls command
        execve(path_ls, ls_args, ls_env);
        // If execve returns, it failed
        perror("execve");
        exit(EXIT_FAILURE);
    } else { // Parent process
        close(pipefd[1]); // Close write end of pipe
        
        // Read from pipe and write to output file
        char buffer[4096];
        ssize_t bytes_read;
        while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            fwrite(buffer, 1, bytes_read, output_file);
        }
        
        // Close file and wait for child process to finish
        fclose(output_file);
        wait(NULL);
    }
    
    return 0;
}
