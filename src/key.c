/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:50:56 by elabasqu          #+#    #+#             */
/*   Updated: 2021/10/05 17:50:58 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_struct *struc)
{
	if (keycode == 13)
		struc->keylst.w = 1;
	if (keycode == 0)
		struc->keylst.a = 1;
	if (keycode == 1)
		struc->keylst.s = 1;
	if (keycode == 2)
		struc->keylst.d = 1;
	if (keycode == 53)
		close_window(struc);
	return (0);
}

void	init_press(t_struct *struc)
{
	struc->keylst.w = 0;
	struc->keylst.s = 0;
	struc->keylst.a = 0;
	struc->keylst.d = 0;
}

int	key_unpress(int keycode, t_struct *struc)
{
	if (keycode == 13)
		struc->keylst.w = 0;
	if (keycode == 0)
		struc->keylst.a = 0;
	if (keycode == 1)
		struc->keylst.s = 0;
	if (keycode == 2)
		struc->keylst.d = 0;
	return (0);
}
