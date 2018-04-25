/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:07:50 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 15:07:51 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_math.h"

/*
** Linear interpolation of a value between start and end at t >= 0 && t <= 1
*/

float		lerp(const float start, const float end, const float t)
{
	return ((1 - t) * start + t * end);
}