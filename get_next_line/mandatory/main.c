#include "get_next_line.h"

int main()
{
    int fd = open("text.txt", O_RDONLY);
    int i = 11;
    while(i--)
        printf("%s", get_next_line(fd));
}