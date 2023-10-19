#include "get_next_line.h"



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

/*int main(){
	int fd_reading = open("file_to_read.txt", O_RDONLY);
	if (fd_reading < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}
    printf("%s\n", get_next_line(fd_reading));
    close(fd_reading);
}*/
