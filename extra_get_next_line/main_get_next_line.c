#include "get_next_line.h"

int main(void)
{
   //checking --- char *get_next_line(int fd)) ---
	int fd_open = open("file_to_read.txt", O_RDONLY);
	printf("%s", get_next_line(fd_open));
    printf("%s", get_next_line(fd_open));
    printf("%s", get_next_line(fd_open));
    printf("%s", get_next_line(fd_open));

	close(fd_open);
		return (0);
}