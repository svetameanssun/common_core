# ifndef SO_LONG_H
# define SO_LONG_H


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strncpy_gnl(char *dest, char *src, size_t n);
int		count_till_nl(char *str);
int		count_after_nl(char *str);
int		check_nl_escape(char *str);
char	*copy_first_line(char *str);
char	*read_all(int fd, char *str);
char	*update_statik_str(char *old_str);
char	*get_next_line(int fd);



int check_chars(char ** matrix);
int check_elem(char ** map_matrix, int i); //here int i, because of the NORM  and ENEMY!!!
int check_map_name(char *map_name);
int check_rectangular(char ** map_matrix);
int check_walls(char** map_matrix);
char **map_to_matrix(char *map_name);
int valid_map(char * map_name);
int count_map_lines(char * map_name);
//int main(void);
size_t	ft_strlen_sl(const char *str); //the 3rd strlen in the project

void ft_print_matrix(char **matrix); // REMOVE OR CHANGE


# endif