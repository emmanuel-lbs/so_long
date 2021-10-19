/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:54:57 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/19 16:40:08 by elabasqu         ###   ########lyon.fr   */
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

void	draw_texture(t_struct *s, int x, int y, t_texture texture)
{
	int		tx;
	int		ty;
	float	ratio_y;
	float	ratio_x;

	tx = 0;
	ratio_x = texture.height / (float)s->size_of_block.x;
	ratio_y = texture.width  / (float)s->size_of_block.y;
//	printf(" texture height = %d\n",texture.height);
//	printf("size block y %d\n",s->size_of_block.y);
//	printf("texture width %d\n",texture.width);
//	printf(" size block x %d\n",s->size_of_block.x);

	while (tx < s->size_of_block.x)
	{
		ty = 0;
		while (ty < s->size_of_block.y)
		{
			s->data.addr[(x + ty) * (s->data.line_length / 4)  + (y + tx )] = texture.addr[(int)((int)(tx * ratio_x) + (int)(ty * ratio_y ) * texture.line_length / 4 )];
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
	while (x < s->width * s->size_of_block.x)
	{
		y = 0;
		i2 = 0;
		while (y < s->height * s->size_of_block.y)
		{
			//			printf("x == %d      y == %d\n",x, y);
			print_text(s, s->map[i2][i]);
		//	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/P.xpm", &s->textu.width, &s->textu.height);
			s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
			//			printf("%d\n",s->textu.line_length);
			draw_texture(s, y, x, s->textu);
			mlx_put_image_to_window(s->window, s->win, s->data.img, 0, 0);
			mlx_put_image_to_window(s->window, s->win, s->textu.ptr, 700, 150);
			y += s->size_of_block.y;
			i2++;
//			printf("i et i2 %d    %d\n",i, i2);
		}
		x += s->size_of_block.x;
		i++;
	}
}
