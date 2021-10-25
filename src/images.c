/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:48 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/25 13:58:49 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_texture(t_struct *s, t_texture t, int img, t_point_int new_size)
{
	int		tx;
	int		ty;
	float	ratio_y;
	float	ratio_x;

	tx = 0;
	ratio_x = t.height / (float)new_size.x;
	ratio_y = t.width / (float)new_size.y;
	while (tx < new_size.x)
	{
		ty = 0;
		while (ty < new_size.y)
		{
			s->data[img].addr[ty * (s->data[img].lenline / 4) + tx] \
				= t.addr[(int)(tx * ratio_x) + ((int)(ty * ratio_y)) \
				* t.lenline / 4];
			ty++;
		}
		tx++;
	}
}

static void	rezize_img_part_two(t_struct *s)
{
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/E.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, img_E, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/P.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, img_P, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/FINAL.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, img_FIN, (t_point_int){s->r1, s->r2});
}

void	rezize_img(t_struct *s)
{
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/0.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, 0, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/1.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, 1, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/C.xpm", \
			&s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, \
			&s->textu.lenline, &s->textu.en);
	draw_texture(s, s->textu, img_C, s->size_of_block);
	rezize_img_part_two(s);
}

void	create_img(t_struct *s)
{
	s->data[0].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[0].addr = (int *)mlx_get_data_addr(s->data[0].img, \
			&s->data[0].bit, &s->data[0].lenline, &s->data[0].en);
	s->data[1].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[1].addr = (int *)mlx_get_data_addr(s->data[1].img, \
			&s->data[1].bit, &s->data[1].lenline, &s->data[1].en);
	s->data[img_E].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[img_E].addr = (int *)mlx_get_data_addr(s->data[img_E].img, \
			&s->data[img_E].bit, &s->data[img_E].lenline, &s->data[img_E].en);
	s->data[img_C].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[img_C].addr = (int *)mlx_get_data_addr(s->data[img_C].img, \
			&s->data[img_C].bit, &s->data[img_C].lenline, &s->data[img_C].en);
	s->data[img_P].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[img_P].addr = (int *)mlx_get_data_addr(s->data[img_P].img, \
			&s->data[img_P].bit, &s->data[img_P].lenline, &s->data[img_P].en);
	s->data[img_FIN].img = mlx_new_image(s->window, s->r1, s->r2);
	s->data[img_FIN].addr = (int *)mlx_get_data_addr(s->data[img_FIN].img, \
			&s->data[img_FIN].bit, &s->data[img_FIN].lenline, \
			&s->data[img_FIN].en);
	s->put_data.img = mlx_new_image(s->window, s->r1, s->r2);
	s->put_data.addr = (int *)mlx_get_data_addr(s->put_data.img, \
			&s->put_data.bit, &s->put_data.lenline, &s->put_data.en);
}
