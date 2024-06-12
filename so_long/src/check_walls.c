#include "../include/so_long.h"

int check_walls(char** map_matrix)
{
    int x;
    int lines_len;
    int matrix_len;

    x = 0;
    matrix_len = ft_matrix_len(map_matrix);
    lines_len = ft_strlen_sl(*map_matrix);
    while(x < lines_len) 
    {
        if(map_matrix[0][x] == '1' && map_matrix[matrix_len-1][x] == '1')
            x++;
        else
            return(1);
    }
    x = 1;
    while(x < matrix_len - 1)
    {
        if(map_matrix[x][0] != '1' || map_matrix[x][lines_len - 1] != '1')
            return(1);
        x++;
    }
    return(0);
}

/*int main()
{
	char **split_str;
	char str[] = {"11111,10001,10001,10001,10001,1C1C0,1EEE1,11111"};
	split_str = ft_split(str,',');
	printf("%d", check_walls(split_str));
	return(0);
}*/
