/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:32:02 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/05 17:29:43 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*first_line(t_struct *struc)
{
	char	*line;
	int		ret_gnl;

	ret_gnl = 1;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(struc->fd, &line);
		if (ret_gnl == -1)
			print_error("Error\nget_next_line crash\n");
		if (line[0])
		{
			line = ft_strjoin(line, "\n");
			if (!line)
				print_error("Error\nstrjoin crash\n");
			break ;
		}
		free(line);
	}
	if (ret_gnl == 0)
		print_error("Error\nmap missing\n");
	return (line);
}

void	end_of_file(char *line_for_free, t_struct *struc)
{
	char	*line;
	int		ret_gnl;

	ret_gnl = 1;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(struc->fd, &line);
		if (ret_gnl == -1)
			print_error("Error\nget_next_line crash\n");
		if (line[0])
		{
			free(line);
			free(line_for_free);
			print_error("Error\ndon't write after the map\n");
		}
		free(line);
	}
}

char	**create_map(t_struct *struc)
{
	char	**map;
	char	*line;
	char	*big_line;
	int		ret_gnl;

	ret_gnl = 1;
	big_line = first_line(struc);
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(struc->fd, &line);
		if (ret_gnl == -1)
		{
			free(big_line);
			print_error("Error\nget_next_line crash\n");
		}
		if (!line[0])
		{
			free(line);
			break ;
		}
		big_line = ft_strjoin(ft_strjoin(big_line, line), "\n");
		free(line);
		if (!big_line)
			print_error("Error\nstrjoin crash\n");
	}
	end_of_file(big_line, struc);
	map = ft_split(big_line, '\n');
	if (!map)
		print_error("Error\nsplit error\n");
	free(big_line);
	return (map);
}
