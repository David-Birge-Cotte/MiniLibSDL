/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:55 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:57 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/v2f.h"

t_vector2f	v2f(float x, float y)
{
	t_vector2f	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector2f	v2f_add(t_vector2f v1, t_vector2f v2)
{
	return (v2f(v1.x + v2.x, v1.y + v2.y));
}

t_vector2f	v2f_sub(t_vector2f v1, t_vector2f v2)
{
	return (v2f(v1.x - v2.x, v1.y - v2.y));
}

t_vector2f	v2f_unit(t_vector2f v)
{
	float 		mag;

	mag = v2f_mag(v);
	return (v2f(v.x / mag, v.y / mag));
}

t_vector2f	v2f_scale(t_vector2f v, float factor)
{
	return (v2f(v.x * factor, v.y * factor));
}