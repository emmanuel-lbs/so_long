
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
int             key_unpress(int keycode, t_struct *struc);
int            key_press(int keycode, t_struct *struc);
void	rezize_img(t_struct *s);
int	mlx_begin(t_struct *struc);
int	close_window(t_struct *struc);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	display(t_struct *struc);
int		move(t_struct *struc);
void	ft_free_struc(t_struct *struc);
void	check_start_point(int x, int y, t_struct *struc);
e_valid_caract	check_valid_caract(char c);
#endif
