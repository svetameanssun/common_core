#ifndef T_POINT_FLOOD_FILL
# define T_POINT_FLOOD_FILL

typedef struct s_point
{
    int x;
    int y;
}           t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif