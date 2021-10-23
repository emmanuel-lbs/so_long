/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:32:28 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/23 18:51:47 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_valid_caract	check_valid_caract(char c)
{
	if (c == '1' || c == '0')
		return (nu);
	if (c == 'C')
		return (C);
	if (c == 'E')
		return (E);
	if (c == 'P')
		return (P);
	return (not_valid);
}

void	check_start_point(int x, int y, t_struct *struc)
{
	if (struc->start_point.x != -1)
	{
		ft_free_struc(struc);
		print_error("Error\ndont put two point ");
	}
	struc->start_point.x = y + 0.5;
	struc->start_point.y = x + 0.5;
}

void	ft_free_struc(t_struct *struc)
{
	if (struc->map)
		ft_free_double_char(struc->map);
	if (struc->colect_point)
		free(struc->colect_point);
}
