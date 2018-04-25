/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:59 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:24:04 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_math.h"

t_vector2i	v2i(int x, int y)
{
	t_vector2i	vec2i;

	vec2i.x = x;
	vec2i.y = y;
	return (vec2i);
}

t_vector2i	v2i_add(t_vector2f v1, t_vector2f v2)
{
	return (v2i(v1.x + v2.x, v1.y + v2.y));
}

t_vector2i	v2i_sub(t_vector2f v1, t_vector2f v2)
{
	return (v2i(v1.x - v2.x, v1.y - v2.y));
}

t_vector2i	v2i_unit(t_vector2i vec2i)
{
	float 		mag;

	mag = v2i_mag(vec2i);
	return (v2i(vec2i.x / mag, vec2i.y / mag));
}

t_vector2i	v2i_scale(t_vector2i v, float factor)
{
	return (v2i(v.x * factor, v.y * factor));
}