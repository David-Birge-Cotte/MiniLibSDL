/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:59:36 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/02 10:59:36 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

t_color	*ray_trace(t_uint32 x, t_uint32 y, t_app *app)
{
	t_color		*color;
	static t_uint32	seed = 42;
	t_uint32		rng;

	seed++;
	rng = rand_r(&seed);
	color = new_color(rng, rng, rng, 255);
	return (color);
}