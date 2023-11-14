#include "get_next_line.h"

/* void test(void)
{
    system("leaks -q a.out");
} */

int main(void)
{
 /*    atexit(test); */
    int fd_open = open("file_to_read_1.txt", 0 | O_CREAT);
    char *str = get_next_line(fd_open);
    char *str2 = get_next_line(fd_open2);
    char *str3 = get_next_line(fd_open3);
    printf("%s", str);
    free(str);
    free(str2);
    free(str3);
    return (0);
}