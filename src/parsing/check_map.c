/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:32:29 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/23 18:12:49 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	nb_of_c_in_map(char **map, char c)
{
	int	i;
	int	y;
	int	nb_of_c;

	nb_of_c = 0;
	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
			if (map[i][y] == c)
				nb_of_c++;
	}
	return (nb_of_c);
}

void	init_point(char **map, t_struct *struc)
{
	struc->nb_of_colect = nb_of_c_in_map(map, 'C');
	struc->colect_point = malloc(sizeof(t_point) * struc->nb_of_colect);
	if (!struc->colect_point)
	{
		ft_free_struc(struc);
		print_error("Error\nmalloc\n");
	}
	struc->start_point.x = -1;
	struc->colect_point[0].x = -1;
	struc->exit_point.x = -1;
	struc->nb_of_colect = 0;
}

void	check_exist_point(t_struct *struc)
{
	if (struc->start_point.x == -1)
	{
		ft_free_struc(struc);
		print_error("Error\nyou have to put point start");
	}
	if (struc->colect_point[0].x == -1)
	{
		ft_free_struc(struc);
		print_error("Error\nyou have to put colect point");
	}
	if (struc->exit_point.x == -1)
	{
		ft_free_struc(struc);
		print_error("Error\nyou have to put exit point");
	}
}

void	check_intruder(char **map, t_struct *struc)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x] && map[x][++y])
		{
			if (!(check_valid_caract(map[x][y])))
			{
				printf("Error\ncaractere %c invalid in the map", map[x][y]);
				ft_free_struc(struc);
				exit(-1);
			}
			if (check_valid_caract(map[x][y]) == P)
				check_start_point(y, x, struc);
			if (check_valid_caract(map[x][y]) == E)
				struc->exit_point = (t_point){y, x};
			if (check_valid_caract(map[x][y]) == C)
				struc->colect_point[struc->nb_of_colect++] = (t_point){y, x};
		}
	}
	struc->height = x;
	struc->width = y;
}

void	check_line(char **map)
{
	int		i;
	size_t	len_first_line;

	len_first_line = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len_first_line)
		{
			ft_free_double_char(map);
			print_error("Error\nthe map is not rectangular\n");
		}
	}
}
