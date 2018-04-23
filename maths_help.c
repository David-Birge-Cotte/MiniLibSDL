/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:42 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:44 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/*
** Linear interpolation of a value between start and end at t >= 0 && t <= 1
*/
float		lerp(const float start, const float end, const float t)
{
	return ((1 - t) * start + t * end);
}

/*
** Maps a value from the input range to the ouput range
** ex: input = 6, input range = 0-10, output range = 0-20
**    -> returns (12)
*/
float		map(float input, t_vector2f input_range, t_vector2f output_range)
{
	float	output;
	float	slope;

	slope = (output_range.y - output_range.x) / (input_range.y - input_range.x);
	output = output_range.x + slope * (input - input_range.x);
	return (output);
}
