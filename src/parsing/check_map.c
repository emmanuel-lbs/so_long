#include "../../includes/so_long.h"

e_valid_caract	check_valid_caract(char c)
{
	if (c == '1' || c == '0')
		return (nu);
	if (c == 'C')
		return (C);
	if (c == 'E')
		return (E);
	if (c == 'P')
		return (P);
	return (not_valid);
}

t_point check_point(int x, int y, t_point point)
{
	t_point ok_point;

	if (point.x != -1)
		print_error("Error\ndont put two point ");
	ok_point.x = y + 0.5;
	ok_point.y = x + 0.5;
	return (ok_point);
}

int		nb_of_c_in_map(char **map, char c)
{
	int i;
	int y;
	int nb_of_c;

	nb_of_c = 0;
	i = -1;
	while(map[++i])
	{
		y = -1;
		while(map[i][++y])
			if (map[i][y] == c)
				nb_of_c++;
	}
	return (nb_of_c);
}

void	init_point(char **map, t_struct *struc)
{
	struc->nb_of_exit =  nb_of_c_in_map(map, 'E');
	struc->nb_of_colect =  nb_of_c_in_map(map, 'C');
	struc->colect_point = malloc(sizeof(t_point) * struc->nb_of_colect);
	if (!struc->colect_point)
		print_error("Error\nmalloc\n");
	struc->exit_point = malloc(sizeof(t_point) * struc->nb_of_exit);
	if (!struc->exit_point)
		print_error("Error\nmalloc\n");
	struc->start_point.x = -1;
	struc->colect_point[0].x = -1;
	struc->exit_point[0].x = -1;
}

void check_exist_point(t_struct *struc)
{
	if (struc->start_point.x == -1)
		print_error("Error\nyou have to put point start");
	if (struc->colect_point[0].x == -1)
		print_error("Error\nyou have to put colect point");
	if (struc->exit_point[0].x == -1)
		print_error("Error\nyou have to put exit point");
}

void	check_intruder(char **map, t_struct *struc)
{
	int	x;
	int	y;
	int nb_exit;
	int nb_colect;

	x = -1;
	nb_colect = -1;
	nb_exit = -1;
	init_point(map, struc);

	while (map[++x])
	{
		y = -1;
		while (map[x] && map[x][++y])
		{
			if (!(check_valid_caract(map[x][y])))
			{
				printf("Error\ncaractere %c invalid in the map", map[x][y]);
				exit(-1);
			}
			if (check_valid_caract(map[x][y]) == P)
				struc->start_point = check_point(y, x, struc->start_point);
			if (check_valid_caract(map[x][y]) == E)
				struc->exit_point[++nb_exit] = (t_point){y, x};
			if (check_valid_caract(map[x][y]) == C)
				struc->colect_point[++nb_colect] = (t_point){y, x};
		}
	}
	check_exist_point(struc);
}

void	check_line(char **map)
{
	int i;
	size_t len_first_line;


	len_first_line = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
		if (ft_strlen(map[i]) != len_first_line)
			print_error("Error\nthe map is not rectangular\n");
}