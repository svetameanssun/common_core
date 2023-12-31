#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Read the file letter by letter

int main(void)
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
	while(res_read > 0 && c != '\n')
	{

		printf("%c", c);
		res_read = read(file, &c, 1);
	}
	close(file);

	return(0);
}
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

/*int main()
{
	//char str[] = "1234567890";
	char *str;

	str = malloc(sizeof(char) * (9 + 1));
	str[9] = '\0';
	int fd = open("file_to_read.txt", O_RDONLY);
	read(fd,str, 9);
	printf("%s", str);
	//printf("%d", sizeof(str));
	//close(fd);
	return 0;
	
}*/

/*int main()
{
	char buffer;

	int fd_read = open("file_to_read.txt", O_RDONLY);
	int fd_write = open("file_to_write.txt", O_APPEND);

	if (fd_read < 0 || fd_write < 0)
		{
			printf("ERROR ERROR ERROR");
			return(1);
		}
	int res_read = 1;//read(fd_read, &buffer,1);
	//write(fd_write, &buffer,1);
	while(res_read > 0)
	{
		//res_read= read(fd_read,&buffer,1);
		res_read = read(fd_read, &buffer,1);
		if (res_read)
			write(fd_write, &buffer, 1);
	}
	
	close(fd_read);
	close(fd_write);
	return(0);
	
}*/

/*int main()
{
	int buff_size = 5;
	char *buffer;
	buffer = malloc (sizeof(char) * (buff_size + 1));
	
	int fd_read_open = open("file_to_read.txt", O_RDONLY);
	printf("Print int_read_open: %d\n", fd_read_open);
	//int fd_write_open = open("file_to_write.txt", O_WRONLY);
	if(buffer==NULL || fd_read_open < 0) //||fd_write_open < 0
	{
		printf("ERROR ERROR ERROR");
		return (0);
	}
	
	int fd_reading = 1;
	//fd_reading = read(fd_read_open, buffer, buff_size);
	//printf("First reading: %d bytes\n", fd_reading);
	int  i = 0;
	while(fd_reading > 0)
	{
		i = 0;
		fd_reading = read(fd_read_open, buffer, buff_size);
		printf("Reading: %d bytes\n", fd_reading);
		buffer[fd_reading] = '\0';
		while(buffer[i] !='\0')
		{
			printf("%d - ( %c )\n", i,buffer[i] );
			//write(fd_write_open, buffer, buff_size);
			i++;
		}
		
	}
	
	//close(fd_write_open);
	close(fd_read_open);

	return(0);
}*/
