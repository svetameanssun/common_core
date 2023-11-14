#include "get_next_line_bonus.h"

int main(void)
{
   //checking --- char *get_next_line(int fd)) ---
	int fd_open = open("file_to_read1.txt", O_RDONLY);
	printf("%s", get_next_line(33));
    /*printf("%s", get_next_line(fd_open));
    printf("%s", get_next_line(fd_open));
    printf("%s", get_next_line(fd_open));*/
   /* printf("%d", get_next_line_bonus(3));
    printf("%d", get_next_line_bonus(3));*/

	close(fd_open);
		return (0);
}
