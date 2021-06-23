#include "../../includes/so_long.h"

int	check_arg(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		print_error("Error\nnumber of arguments\n");
	while (av[1][i])
		i++;
	if (i < 5)
		i = -1;
	if (i != -1 && av[1][--i] != 'r')
		i = -1;
	if (i != -1 && av[1][--i] != 'e')
		i = -1;
	if (i != -1 && av[1][--i] != 'b')
		i = -1;
	if (i != -1 && av[1][--i] != '.')
		i = -1;
	if (i == -1)
		print_error("Error\ninvalid .ber fil\n");
	i = open(av[1], O_RDONLY);
	if (i == -1)
		print_error("Error\nthe map does not exist\n");
	return (i);
}

char	**parsing(int ac, char **av, t_struct *struc)
{
	char	**map;

	struc->fd = check_arg(ac, av);
	map = create_map(struc);
	check_intruder(map, struc);
	check_line(map);
//	int i = -1;
//	while (map[++i])
//		printf("%s\n",map[i]);
//
//	printf("C = %d\n",struc->nb_of_colect);
//	printf("P = %d\n",struc->nb_of_exit);
//
	return (map);
}
