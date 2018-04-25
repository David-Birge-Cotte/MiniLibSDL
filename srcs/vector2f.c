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

#include "../includes/graphics.h"

t_vector2f	*new_vector2f(float x, float y)
{
	t_vector2f	*vector2i;

	vector2i = ft_memalloc(sizeof(t_vector2f));
	vector2i->x = x;
	vector2i->y = y;
	return (vector2i);
}

t_vector2f	vector2f(float x, float y)
{
	t_vector2f	vector2i;

	vector2i.x = x;
	vector2i.y = y;
	return (vector2i);
}
