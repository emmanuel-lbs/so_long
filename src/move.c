/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:25:17 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/20 19:08:23 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_move(t_struct *s, int x, int y)
{
	if (s->map[s->start_point.x + x][s->start_point.y + y] != '1' \
			&& s->map[s->start_point.x + x][s->start_point.y + y] != 'E')
		return (1);
	if (s->map[s->start_point.x + x][s->start_point.y + y] == 'E' \
			&& s->nb_collected == s->nb_of_colect)
		return (2);
	return (0);
}

void	all(t_struct *s, int x, int y)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (verif_move(s, x, y) == 1)
	{
		if (s->map[s->start_point.x + x][s->start_point.y + y] == 'C')
			s->nb_collected++;
		s->map[s->start_point.x][s->start_point.y] = '0';
		s->map[s->start_point.x + x][s->start_point.y + y] = 'P';
		s->start_point.x += x;
		s->start_point.y += y;
		printf("%d\n", s->nb_of_move++);
	}
	else if (verif_move(s, x, y) == 2)
	{
		s->start_point.x += x;
		s->start_point.y += y;
	}
}

int	move(t_struct *s)
{
	if (s->keylst.w)
	{
		all(s, -1, 0);
		s->keylst.w = 0;
		return (1);
	}
	else if (s->keylst.s)
	{
		all(s, 1, 0);
		s->keylst.s = 0;
		return (1);
	}
	else if (s->keylst.a)
	{
		all(s, 0, -1);
		s->keylst.a = 0;
		return (1);
	}
	else if (s->keylst.d)
	{
		all(s, 0, 1);
		s->keylst.d = 0;
		return (1);
	}
	return (0);
}
