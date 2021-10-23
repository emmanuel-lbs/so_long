/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:41 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/23 19:00:47 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef enum what_img {
	img_C = 2,
	img_E = 3,
	img_P = 4,
	img_FIN = 5,
}			t_what_img;

typedef enum valid_caract {
	P = 1,
	E = 2,
	C = 3,
	nu = 4,
	not_valid = 0,
}			t_valid_caract;

typedef enum order {
	init,
	check,
}			t_order;

typedef struct s_point_int
{
	int	x;
	int	y;
}		t_point_int;

typedef struct s_point
{
	float	x;
	float	y;
}		t_point;

typedef struct s_keylst
{
	int	w;
	int	a;
	int	s;
	int	d;
}			t_keylst;

//~~~~~~~~~~TEXTURE~~~~~~~~~~~~//

typedef struct s_texture {
	void		*ptr;
	int			*addr;
	int			width;
	int			height;
	int			en;
	int			lenline;
	int			a;
	int			b;
}	t_texture;

//~~~~~~~~MLX STRUCT~~~~~~~~~~~//

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bit;
	int		lenline;
	int		en;
}			t_data;

//~~~~~~~~BASE STRUCT~~~~~~~~~~~//

typedef struct struc {
	t_point_int	start_point;
	t_point		*colect_point;
	t_point		exit_point;
	t_keylst	keylst;
	int			square_height;
	int			square_width;
	char		**map;
	int			height;
	int			width;
	int			r1;
	int			r2;
	t_point_int	size_of_block;
	int			nb_of_move;
	int			nb_of_exit;
	int			nb_of_colect;
	int			nb_collected;
	int			fd;
	void		*window;
	void		*win;
	t_texture	textu;
	t_data		data[6];
	t_data		put_data;
	t_vars		vars;
}				t_struct;
#endif
