
#include "so_long.h"

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

typedef struct s_point
{
		float	x;
		float	y;
}		t_point;

typedef struct	struc {

	t_point start_point;
	t_point *colect_point;
	t_point *exit_point;

	char **map;
	int	nb_of_exit;
	int nb_of_colect;
	int fd;


}				t_struct;
