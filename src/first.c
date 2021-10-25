/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:51:36 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/25 13:49:10 by elabasqu         ###   ########lyon.fr   */
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

int	mlx_begin(t_struct *s)
{
	int		a;
	int		b;
	char	*itoa;

	a = 0;
	b = 0;
	if (s->nb_collected == s->nb_of_colect \
			&& s->map[s->start_point.x][s->start_point.y] == 'E')
	{
		itoa = ft_itoa(s->nb_of_move);
		mlx_put_image_to_window(s->window, s->win, s->data[img_FIN].img, 0, 0);
		mlx_string_put(s->window, s->win, 10, 20, 0, "nb fo step");
		mlx_string_put(s->window, s->win, 120, 21, 0, itoa);
		free(itoa);
		return (0);
	}
	else if (move(s))
	{
		display(s);
	}
	itoa = ft_itoa(s->nb_of_move);
	mlx_string_put(s->window, s->win, 0, 10, 0xFFFFFF, "nb fo step");
	mlx_string_put(s->window, s->win, 110, 11, 0xFFFFF, itoa);
	free(itoa);
	return (0);
}
