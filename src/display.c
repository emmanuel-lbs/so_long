/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:36 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/24 16:35:18 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	cp_texture_to_img(t_struct *s, t_data *texture, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < s->size_of_block.x - 1)
	{
		j = -1;
		while (j++ < s->size_of_block.y - 1)
		{
			s->put_data.addr[(x + i) * (s->put_data.lenline / 4) + y + j] \
				= texture->addr[(int)(i * (texture->lenline / 4) + j)];
		}
	}
}

static void	create_the_image(t_struct *s, char c, int x, int y)
{
	if (c == '0')
		cp_texture_to_img(s, &s->data[0], x, y);
	else if (c == '1')
		cp_texture_to_img(s, &s->data[1], x, y);
	else if (c == 'E')
		cp_texture_to_img(s, &s->data[img_E], x, y);
	else if (c == 'C')
		cp_texture_to_img(s, &s->data[img_C], x, y);
	else if (c == 'P')
		cp_texture_to_img(s, &s->data[img_P], x, y);
}

void	display(t_struct *s)
{
	int	y;
	int	x;
	int	i;
	int	i2;

	i2 = 0;
	y = 0;
	i2 = 0;
	while (y < (s->height) * s->size_of_block.y)
	{
		i = 0;
		x = 0;
		while (x < s->width * s->size_of_block.x)
		{
			create_the_image(s, s->map[i2][i], y, x);
			x += s->size_of_block.x;
			i++;
		}
		y += s->size_of_block.y;
		i2++;
	}
	mlx_put_image_to_window(s->window, s->win, s->put_data.img, 0, 0);
}
