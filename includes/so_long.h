/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:31:37 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/24 16:28:35 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void			ft_free_struc(t_struct *struc);
int				key_unpress(int keycode, t_struct *struc);
int				key_press(int keycode, t_struct *struc);
int				close_window(t_struct *struc);
void			ft_free_struc(t_struct *struc);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~PARSING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void			parsing(int ac, char **av, t_struct *struc);
char			*create_line_map(t_struct *struc);
char			**create_tab_map(char *line_map, t_struct *struc);
void			init_point(char **map, t_struct *struc);
void			check_intruder(char **map, t_struct *struc);
void			check_exist_point(t_struct *struc);
void			check_line(char **map);
void			check_start_point(int x, int y, t_struct *struc);
t_valid_caract	check_valid_caract(char c);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~IMG_MLX~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void			rezize_img(t_struct *s);
void			put_img(t_struct *s, char c, int x, int y);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~ALGO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int				mlx_begin(t_struct *struc);
void			create_img(t_struct *s);
void			display(t_struct *struc);
int				move(t_struct *struc);
#endif
