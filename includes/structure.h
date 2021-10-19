
#include "so_long.h"
#include "../mlx/mlx.h"

typedef enum valid_caract {
	P = 1,
	E = 2,
	C = 3,
	nu = 4,
	not_valid = 0,
}			e_valid_caract;

typedef enum order {
	init,
	check,
}			e_order;

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

typedef	struct s_keylst
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
	int			endian;
	int			line_length;
	int			a;
	int			b;
}	t_texture;

//~~~~~~~~MLX STRUCT~~~~~~~~~~~//

typedef struct  s_vars {
	void        *mlx;
	void        *win;
}               t_vars;

typedef struct  s_data {
	void        *img;
	int        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

//~~~~~~~~BASE STRUCT~~~~~~~~~~~//

typedef struct	struc {

	t_point_int start_point;
	t_point *colect_point;
	t_point exit_point;

	t_keylst keylst;



	int		square_height;
	int		square_width;

	char **map;
	int height;
	int width;
	int R1;
	int R2;
	t_point_int size_of_block;

	int nb_of_move;
	int	nb_of_exit;
	int nb_of_colect;
	int nb_collected;
	int fd;
	t_texture textu;

	void *window;
	void *win;
	t_data		data;
	t_data		data_swap;;
	t_vars		vars;

}				t_struct;
