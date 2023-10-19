#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Read the file letter by letter

/*int main(void)
{
	char c;

	int file = open("file_to_read.txt", O_RDONLY);
	if (file < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}

	int res_read;
	res_read = read(file, &c, 1);
	while(res_read > 0)
	{
		printf("%c", c);
		res_read = read(file, &c, 1);
	}
	close(file);


	return(0);
}*/
// reading a file and writing in another one letter by letter
/*int main(void)
{
	char c;

	int fd_reading = open("file_to_read.txt", O_RDONLY);
	int fd_writing = open("file_to_write.txt", O_WRONLY);
	if (fd_reading < 0 || fd_writing < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}

	int res_read;
	res_read = read(fd_reading, &c, 1);
	while(res_read > 0)
	{

		write(fd_writing, &c, 1);
		res_read = read(fd_reading, &c, 1);

	}
	printf("%d\n", fd_reading);
	printf("%d\n", fd_writing);
	close(fd_reading);
	close(fd_writing);
	return(0);
}*/
// reading a file 9 by 9 letter and writing in another file

/*int main(void)
{
	char *buffer;
	buffer = malloc(sizeof(char)*(10));

	int fd_reading = open("file_to_read.txt", O_RDONLY);
	int fd_writing = open("file_to_write.txt", O_WRONLY);
	if (fd_reading < 0 || fd_writing < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}

	int res_read;
	res_read = read(fd_reading, buffer,9);
	buffer[res_read] = '\0';
	while(res_read > 0)
	{
		write(fd_writing, buffer, res_read);
		//write(1, "\n", 1);
		write(1, buffer, res_read);
		//write(1, "\n", 1);
		//printf("%d\n", res_read);
		res_read = read(fd_reading, buffer, 9);
		buffer[res_read] = '\0';


	}
	printf("%d\n", fd_reading);
	printf("%d\n", fd_writing);
	close(fd_reading);
	close(fd_writing);
	return(0);
}*/

// preprocessor macro (aka constant) to tell us how much to read at a time
/*#define BUFFER_SIZE 4
//it ignores the remainder of the read string after new line
int	main(void)
{
	static char *buffer;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	int fd_reading = open("file_to_read.txt", O_RDONLY);
	if (fd_reading < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}

	int res_read;
	res_read = 1;
    // read while there's stuff left to read
	while (res_read > 0)
	{
		res_read = read(fd_reading, buffer, BUFFER_SIZE);
		buffer[res_read] = '\0';

		// Print buffer until newline or null char
		int i = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
		{
			write(1, &buffer[i], 1);
			i++;
		}
        write(1, "\n", 1);
	}
	free(buffer);
	close(fd_reading);
	return (0);
}*/

//preparation for get next line
/*#define BUFFER_SIZE 4


char *get_next_line(int fd)
{   
    static char *remaining = NULL;
	char *buffer;
    char *line;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//comprobar malloc



	int i;
	i = 1;
    // read while there's stuff left to read
	while (("remaining doesn't include a newline") && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		//if i == -1, then BAD ERROR, we must free everything, buffer and remaining, and return NULL
        "strjoin add buffer to remaining ";
	}
	free(buffer);
    line = "put (extract) here a copy of the FIRST line from remaining";
	remaining = "remaining (itself) but only after the line we extracted earlier or NULL if nothing left";
	//esa funcion tiene que hacer la copia nueva y liberar el str antiguo
	return (line);
}

int main(){
	int fd_reading = open("file_to_read.txt", O_RDONLY);
	if (fd_reading < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}
    printf("%s\n", get_next_line(fd_reading));
    close(fd_reading);
}*/
