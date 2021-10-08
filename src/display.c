/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:57 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/05 18:25:09 by elabasqu         ###   ########lyon.fr   */
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
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/0.xpm", &a, &b);
	else if (c == '0')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/1.xpm", &a, &b);
	else if (c == 'E')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/E.xpm", &a, &b);
	else if (c == 'C')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/C.xpm", &a, &b);
	else if (c == 'P')
		s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/P.xpm", &a, &b);
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
	while (i < s->height)
	{
		y = 0;
		i2 = 0;
		while (i2 < s->width)
		{
			print_text(s, s->map[i][i2]);
			s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.bpp, &s->textu.len, &s->textu.endian);
			mlx_put_image_to_window(s->window, s->win, s->textu.ptr, y, x);
			y += s->size_of_block.x;
			i2++;
		}
		x += s->size_of_block.y;
		i++;
	}
}
/*
//void	display(t_struct *s)
//{
//
//	int y;
//	int x;
//	int test;
//	int b;
//	b = 200;
//	testruct = 200;
//
//	x = 0;
//	while (x <= s->size_of_block.x)
//	{
//		y = -1;
//		while (y <= s->size_of_block.y)
//		{
//			s->textu.ptr = mlx_xpm_file_to_image(s->window, "./texture/brick.xpm", &test, &test);
//			s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.bpp, &s->textu.len, &s->textu.endian);
//			mlx_put_image_to_window(s->window, s->win, s->textu.ptr, 0, 0);
//			y += s->size_of_block.y;
//		}
//		x += s->size_of_block.x;
//	}
//
//}
*/
