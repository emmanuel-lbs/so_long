/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:57 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/15 16:03:02 by elabasqu         ###   ########lyon.fr   */
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

void	put_pixel(t_struct *s, int x, int y, int color)
{
	char	*dst;

	if (x > s->width - 1 || x < 0 || y >= s->height - 1 || y < 0)
		return ;
	dst = s->data.addr + (y * s->data.line_length + x
			* (s->data.bits_per_pixel / 8));
	if ((color & 0x00FFFFFF) == 0)
		return ;
	*(unsigned int *)dst = color;
}

void	draw_texture(t_struct *s, int x, int y, t_texture texture)
{
	int		tx;
	int		ty;
	float	ratio_y;
	float	ratio_x;

	tx = 0;
	ratio_x = texture.height / (float)s->size_of_block.y;
	ratio_y = texture.width  / (float)s->size_of_block.x;
	printf(" texture height = %d\n",texture.height);
	printf("size block y %d\n",s->size_of_block.y);
	printf("texture width %d\n",texture.width);
	printf(" size block x %d\n",s->size_of_block.x);

	while (tx < s->size_of_block.x)
	{
		ty = 0;
		while (ty < s->size_of_block.y)
		{
			put_pixel(s, x + tx, y + ty, texture.addr[(int)((int)(ty * ratio_y) *texture.width + (int)(tx * ratio_x))]);
			ty++;
		}
		tx++;
	}
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
	s->size_of_block.y = 200;
	s->size_of_block.x = 200;
	while (i < s->height)
	{
		y = 0;
		i2 = 0;
		while (i2 < s->width)
		{
			print_text(s, s->map[i][i2]);
			s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.b, &s->textu.endian);
			draw_texture(s, i, i2, s->textu);
			mlx_put_image_to_window(s->window, s->win, s->data.img, y, x);
			y += s->size_of_block.x;
			i2++;
		}
		x += s->size_of_block.y;
		i++;
	}
}
