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

#include "../../includes/ft_math.h"

t_vector2f	v2f(float x, float y)
{
	t_vector2f	vec2f;

	vec2f.x = x;
	vec2f.y = y;
	return (vec2f);
}

t_vector2f	v2f_add(t_vector2f v1, t_vector2f v2)
{
	t_vector2f	vec2f;

	vec2f = v2f(v1.x + v2.x, v1.y + v2.y);
	return (vec2f);
}

t_vector2f	v2f_sub(t_vector2f v1, t_vector2f v2)
{
	t_vector2f	vec2f;

	vec2f = v2f(v1.x - v2.x, v1.y - v2.y);
	return (vec2f);
}

float		v2f_magnitude(t_vector2f vec2f)
{
	return (sqrtf(vec2f.x * vec2f.x + vec2f.y * vec2f.y));
}