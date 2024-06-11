#include "../include/so_long.h"

int check_rectangular(char ** map_matrix)
{
    int i;
    size_t example_line_len;
    size_t current_line_len;

    i = 1;
    example_line_len = ft_strlen(*map_matrix);
    current_line_len = 0;
    while(map_matrix[i])
    {
        
        current_line_len = ft_strlen(map_matrix[i]);
        printf("%ld\n", current_line_len);
        if (example_line_len != current_line_len)
            return(1);
        i++;
    }
    return(0);
}

/*int main()
{
	char **split_str;
	char str[] = {"11111111,11111111,11111111,00000000,00000009,CC1CCCCC,EEEEEEEE,NNNNPPP1"};
	split_str = ft_split(str,',');
	printf("%d", check_rectangular(split_str));
	return(0);
}*/