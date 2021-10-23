/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:33:29 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/23 19:00:00 by elabasqu         ###   ########lyon.fr   */
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
	s->r1 = s->size_of_block.x * s->width;
	s->r2 = s->size_of_block.y * s->height;
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
	printf("r2 = %d r1 = %d \n", s->r2, s->r1);
	printf("size->y == %d\n", s->size_of_block.y);
	printf("size->x == %d\n", s->size_of_block.x);
}

int	main(int ac, char **av)
{
	t_struct	s;

	parsing(ac, av, &s);
	check_reso(&s);
	//printeur(&s);
	s.window = mlx_init();
	s.win = mlx_new_window(s.window, s.r1, s.r2, "MANU_SO_LONG");
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
