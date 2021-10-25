/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:32:32 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/24 15:33:16 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_arg(int ac, char **av)
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
	i = open(av[1], O_RDWR);
	if (i == -1)
		print_error("Error\nthe map does not exist\n");
	return (i);
}

static int	check_valid_mid_line(t_struct *struc)
{
	int	i;
	int	len_line;

	len_line = ft_strlen(struc->map[0]) - 1;
	i = 0;
	while (struc->map[++i])
	{
		if (struc->map[i][0] != '1')
		{
			printf("Error\nleft side in map is invalid");
			ft_free_struc(struc);
			exit(-1);
		}
		else if (struc->map[i][len_line] != '1')
		{
			printf("Error\nright side in map is invalid");
			ft_free_struc(struc);
			exit(-1);
		}
	}
	return (i - 1);
}

static void	check_valid_map(t_struct *struc)
{
	int	i;
	int	len_line;

	len_line = ft_strlen(struc->map[0]) - 1;
	i = -1;
	while (struc->map[0][++i])
	{
		if (struc->map[0][i] != '1')
		{
			printf("Error\nfirst line in map is invalid");
			ft_free_struc(struc);
			exit(-1);
		}
	}
	len_line = check_valid_mid_line(struc);
	i = -1;
	while (struc->map[len_line][++i])
	{
		if (struc->map[len_line][i] != '1')
		{
			printf("Error\nlast line in map is invalid");
			ft_free_struc(struc);
			exit(-1);
		}
	}
}

void	parsing(int ac, char **av, t_struct *struc)
{
	char	*line_map;

	struc->fd = check_arg(ac, av);
	line_map = create_line_map(struc);
	struc->map = create_tab_map(line_map, struc);
	init_point(struc->map, struc);
	check_intruder(struc->map, struc);
	check_exist_point(struc);
	check_line(struc->map);
	check_valid_map(struc);
	struc->nb_collected = 0;
	struc->nb_of_move = 0;
}
