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
	t_vector2i	*vector2i;

	vector2i = ft_memalloc(sizeof(t_vector2i));
	vector2i->x = x;
	vector2i->y = y;
	return (vector2i);
}

t_vector2i	vector2i(int x, int y)
{
	t_vector2i	vector2i;

	vector2i.x = x;
	vector2i.y = y;
	return (vector2i);
}
