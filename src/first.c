/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:51:36 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/20 19:18:59 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_struct *struc)
{
	mlx_destroy_window(struc->window, struc->win);
	ft_free_struc(struc);
	printf("perfect close\n");
	exit(-1);
	return (0);
}

int	mlx_begin(t_struct *struc)
{
	int	a;
	int	b;

	a = 0;
	b = 0;

	if (struc->nb_collected == struc->nb_of_colect && struc->map[struc->start_point.x][struc->start_point.y] == 'E')
	{
		mlx_put_image_to_window(struc->window, struc->win, struc->data[img_FIN].img, 0, 0);
		return (0);
	}
	else if (move(struc))
	{
		display(struc);
	}
	mlx_do_sync(struc->window);
	return (0);
}
