/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:57 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/20 19:18:51 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_text(t_struct *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (c == '1')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/0.xpm", &s->textu.width, &s->textu.height);
	else if (c == '0')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/1.xpm", &s->textu.width, &s->textu.height);
	else if (c == 'E')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/E.xpm", &s->textu.width, &s->textu.height);
	else if (c == 'C')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/C.xpm", &s->textu.width, &s->textu.height);
	else if (c == 'P')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/P.xpm", &s->textu.width, &s->textu.height);
}

void	put_img(t_struct *s, char c, int x, int y)
{
	if (c == '0')
			mlx_put_image_to_window(s->window, s->win, s->data[0].img, x, y);
	else if (c == '1')
			mlx_put_image_to_window(s->window, s->win, s->data[1].img, x, y);
	else if (c == 'E')
			mlx_put_image_to_window(s->window, s->win, s->data[img_E].img, x, y);
	else if (c == 'C')
			mlx_put_image_to_window(s->window, s->win, s->data[img_C].img, x, y);
	else if (c == 'P')
			mlx_put_image_to_window(s->window, s->win, s->data[img_P].img, x, y);

}

void	display(t_struct *s)
{
	int	y;
	int	x;
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	x = 0;
	while (x < s->width * s->size_of_block.x)
	{
		y = 0;
		i2 = 0;
		while (y < s->height * s->size_of_block.y)
		{
			put_img(s, s->map[i2][i], x, y);
			y += s->size_of_block.y;
			i2++;
		}
		x += s->size_of_block.x;
		i++;
	}
}
