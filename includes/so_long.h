
#ifndef SO_LONG_H
# define SO_LONG_H


# include "structure.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>

void	parsing(int ac, char **av, t_struct *struc);
char	**create_map(t_struct *struc);
void	check_intruder(char **map, t_struct *struc);
void	check_line(char **map);
void	ft_free_struc(t_struct *struc);

#endif
