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

t_vector2i	*new_vector2i(int x, int y)
{
	t_vector2i	*vec2i;

	vec2i = ft_memalloc(sizeof(t_vector2i));
	vec2i->x = x;
	vec2i->y = y;
	return (vec2i);
}

t_vector2i	v2i(int x, int y)
{
	t_vector2i	vec2i;

	vec2i.x = x;
	vec2i.y = y;
	return (vec2i);
}

t_vector2i	v2i_add(t_vector2f v1, t_vector2f v2)
{
	t_vector2i	vec2i;

	vec2i = v2i(v1.x + v2.x, v1.y + v2.y);
	return (vec2i);
}

t_vector2i	v2i_sub(t_vector2f v1, t_vector2f v2)
{
	t_vector2i	vec2i;

	vec2i = v2i(v1.x - v2.x, v1.y - v2.y);
	return (vec2i);
}

float		v2i_magnitude(t_vector2i vec2i)
{
	return (sqrt(vec2i.x * vec2i.x + vec2i.y * vec2i.y));
}