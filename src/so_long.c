/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:33:29 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/20 19:19:21 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_reso(t_struct *s)
{
	if (s->width >= s->height)
	{
		s->size_of_block.x = 1600 / s->width;
		s->size_of_block.y = s->size_of_block.x ;
	}
	else
	{
		s->size_of_block.y = 1300 / s->height;
		s->size_of_block.x = s->size_of_block.y ;
	}
	s->R1 = s->size_of_block.x * s->width;
	s->R2 = s->size_of_block.y * s->height;
}

void	printeur(t_struct *s)
{
	int	i;

	i = -1;
	while (s->map[++i])
		printf("%s\n", s->map[i]);
	printf("P = %d,%d\n", s->start_point.x, s->start_point.y);
	printf("C = %d\n", s->nb_of_colect);
	printf("E = %d\n", s->nb_of_exit);
	printf("height = %d width = %d \n", s->height, s->width);
	printf("R2 = %d R1 = %d \n", s->R2, s->R1);
	printf("size->y == %d\n", s->size_of_block.y);
	printf("size->x == %d\n", s->size_of_block.x);
}

void	create_img(t_struct *s)
{
	s->data[0].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[0].addr = (int *)mlx_get_data_addr(s->data[0].img, &s->data[0].bits_per_pixel, &s->data[0].line_length, &s->data[0].endian);
	s->data[1].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[1].addr = (int *)mlx_get_data_addr(s->data[1].img, &s->data[1].bits_per_pixel, &s->data[1].line_length, &s->data[1].endian);
	s->data[img_E].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[img_E].addr = (int *)mlx_get_data_addr(s->data[img_E].img, &s->data[img_E].bits_per_pixel, &s->data[img_E].line_length, &s->data[img_E].endian);
	s->data[img_C].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[img_C].addr = (int *)mlx_get_data_addr(s->data[img_C].img, &s->data[img_C].bits_per_pixel, &s->data[img_C].line_length, &s->data[img_C].endian);
	s->data[img_P].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[img_P].addr = (int *)mlx_get_data_addr(s->data[img_P].img, &s->data[img_P].bits_per_pixel, &s->data[img_P].line_length, &s->data[img_P].endian);
	s->data[img_FIN].img = mlx_new_image(s->window, s->R1, s->R2);
	s->data[img_FIN].addr = (int *)mlx_get_data_addr(s->data[img_FIN].img, &s->data[img_FIN].bits_per_pixel, &s->data[img_FIN].line_length, &s->data[img_FIN].endian);

}

int	main(int ac, char **av)
{
	t_struct	s;

	parsing(ac, av, &s);
	check_reso(&s);

	printeur(&s);

	s.window = mlx_init();
	s.win = mlx_new_window(s.window, s.R1, s.R2, "MANU_SO_LONG");
	create_img(&s);
	rezize_img(&s);
	display(&s);
	mlx_hook(s.win, 2, 1L << 0, key_press, &s);
	mlx_hook(s.win, 3, 1L << 1, key_unpress, &s);
	mlx_hook(s.win, 17, 0L, close_window, &s);
	mlx_loop_hook(s.window, mlx_begin, &s);
	mlx_loop(s.window);
	return (0);
}
