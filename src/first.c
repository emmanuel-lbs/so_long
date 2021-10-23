/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:51:36 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/22 17:44:44 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_struct *s)
{
	mlx_destroy_window(s->window, s->win);
	ft_free_struc(s);
	printf("perfect close\n");
	exit(-1);
	return (0);
}

void	display_2(t_struct *s)
{
	int	x;
	int	y;

	x = s->start_point.x * s->size_of_block.x ;
	y = s->start_point.y * s->size_of_block.y ;
	put_img(s, s->map[s->start_point.x][s->start_point.y], x, y);
}

int	mlx_begin(t_struct *s)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (s->nb_collected == s->nb_of_colect \
			&& s->map[s->start_point.x][s->start_point.y] == 'E')
	{
		mlx_put_image_to_window(s->window, s->win, s->data[img_FIN].img, 0, 0);
		mlx_string_put(s->window, s->win, 10, 20, 0, "nb fo step");
		mlx_string_put(s->window, s->win, 120, 21, 0, ft_itoa(s->nb_of_move));
		return (0);
	}
	else if (move(s))
	{
		display(s);
	}
	mlx_string_put(s->window, s->win, 0, 10, 0xFFFFFF, "nb fo step");
	mlx_string_put(s->window, s->win, 110, 11, 0xFFFFF, ft_itoa(s->nb_of_move));
	return (0);
}
