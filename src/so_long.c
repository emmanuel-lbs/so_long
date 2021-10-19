/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:33:29 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/19 16:41:47 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_reso(t_struct *s)
{
	s->size_of_block.x = 800 / s->width;
	s->size_of_block.y = 500 / s->height;
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
	printf("P = %d\n", s->nb_of_exit);
	printf("height = %d width = %d \n", s->height, s->width);
	printf("R2 = %d R1 = %d \n", s->R2, s->R1);
	printf("size->y == %d\n", s->size_of_block.y);
	printf("size->x == %d\n", s->size_of_block.x);
}

int	main(int ac, char **av)
{
	t_struct	s;

	parsing(ac, av, &s);
	check_reso(&s);
	printeur(&s);
	s.window = mlx_init();
	s.win = mlx_new_window(s.window, s.R1, s.R2, "MANU_SO_LONG");
	s.data.img = mlx_new_image(s.window, s.R1, s.R2);
	s.data.addr = (int *)mlx_get_data_addr(s.data.img, &s.data.bits_per_pixel, &s.data.line_length, &s.data.endian);
	mlx_loop_hook(s.window, mlx_begin, &s);
	mlx_loop(s.window);
	return (0);
}
