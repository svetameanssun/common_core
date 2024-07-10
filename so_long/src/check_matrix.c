#include "../include/so_long.h"

int check_rectangular(t_map * game)
{
    int i;
    size_t example_line_len;
    size_t current_line_len;

    i = 1;
    example_line_len = ft_strlen_sl(*(game->matrix));
    if (example_line_len > 19)
        manage_prog_error(game, ERROR_SIZE);
    current_line_len = 0;
    while(game->matrix[i])
    {
        
        current_line_len = ft_strlen_sl(game->matrix[i]);
        if (example_line_len != current_line_len)
            return(ERROR_NO_RECT);
        i++;
    }
    return(0);
}

int check_elements(t_map * game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->matrix[i]!= NULL)
	{
		j = 0;
		while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
		{
			if ((game->matrix[i][j] == '1') || (game->matrix[i][j] == '0')
			|| (game->matrix[i][j] == 'P') || (game->matrix[i][j] == 'N')
			|| (game->matrix[i][j] == 'E') || (game->matrix[i][j] == 'C'))
				j++;
			else
                return(ERROR_FORBIDDEN_ELEM);
		}
		i++;
	}
	return(0);
}

int check_walls(t_map * game)
{
    int x;
    int lines_len;
    int matrix_len;

    x = 0;
    matrix_len = ft_matrix_len(game->matrix);
    lines_len = ft_strlen_sl(*(game->matrix));
    game->map_dim.x = lines_len;
    while(x < lines_len) 
    {
        if(game->matrix[0][x] == '1' && game->matrix[matrix_len-1][x] == '1')
            x++;
        else
            return(ERROR_NO_WALLS);
    }
    x = 1;
    while(x < matrix_len - 1)
    {
        if(game->matrix[x][0] != '1' || game->matrix[x][lines_len - 1] != '1')
            return(ERROR_NO_WALLS);
        x++;
    }
    return(0);
}
