/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:11 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:13 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/*
** Clamps a value between a min and max
** float clampf, int clampi
*/

float	clampf(float min, float max, float val)
{
	float ret;

	ret = val;
	if (val > max)
		ret = max;
	else if (val < min)
		ret = min;
	return (ret);
}

int		clampi(int min, int max, int val)
{
	int ret;

	ret = val;
	if (val > max)
		ret = max;
	else if (val < min)
		ret = min;
	return (ret);
}
