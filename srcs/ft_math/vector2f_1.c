/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:01:15 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 16:01:17 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_math.h"

float	v2f_dot(t_vector2f v1, t_vector2f v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	v2f_angle(t_vector2f v1, t_vector2f v2)
{
	return (acosf(v2f_dot(v1, v2) / (v2f_mag(v1) * v2f_mag(v2))) * 180.0 / PI);
}

float	v2f_mag(t_vector2f vec2f)
{
	return (sqrtf(vec2f.x * vec2f.x + vec2f.y * vec2f.y));
}
