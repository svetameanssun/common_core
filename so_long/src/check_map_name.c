#include "../include/so_long.h"

int check_map_name(char *map_name)
{
    int i;

    i = 0;
    while (map_name[i] != '.')
    {
        printf("%c\n", map_name[i]);
        i++;
    }
    return (strncmp(map_name + i, ".ber", 4));
}

int main ()
{
    printf("%d", check_map_name("str.ber"));
}