/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:51:36 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/05 18:19:07 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
	mlx_hook(struc->win, 2, 1L << 0, key_press, struc);
	mlx_hook(struc->win, 3, 1L << 1, key_unpress, struc);
	mlx_hook(struc->win, 17, 0L, close_window, struc);
	if (struc->nb_collected == struc->nb_of_colect && struc->map[struc->start_point.x][struc->start_point.y] == 'E')
	{
		struc->textu.ptr = mlx_xpm_file_to_image(struc->window, "./text/ecran-de-fin-.xpm", &a, &b);
		struc->textu.addr = (int *)mlx_get_data_addr(struc->textu.ptr, &struc->textu.bpp, &struc->textu.len, &struc->textu.endian);
		mlx_put_image_to_window(struc->window, struc->win, struc->textu.ptr, 150, 150);
		return (0);
	}
	else
	{
		move(struc);
		display(struc);
	}
	mlx_do_sync(struc->window);
	return (0);
}
