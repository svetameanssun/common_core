#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point point, char start_char)
{
	if (point.x >= size.x ||  point.x < 0
	|| point.y >= size.y || point.y < 0|| tab[point.y][point.x] != start_char)
	{
		return;
	}

	tab[point.y][point.x] = 'F';
	fill(tab, size, (t_point){point.x - 1, point.y}, start_char);
	fill(tab, size, (t_point){point.x + 1, point.y}, start_char);
	fill(tab, size,(t_point){point.x, point.y -1}, start_char);
	fill(tab, size, (t_point){point.x, point.y +1}, start_char);
}



void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}