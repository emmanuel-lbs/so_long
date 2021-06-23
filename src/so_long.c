
#include "../includes/so_long.h"



int main(int ac, char **av)
{
	char **map;
	t_struct struc;


	map = parsing(ac, av, &struc);
	ft_free_double_char(map);
	free(struc.colect_point);
	free(struc.exit_point);
	return (0);
}
