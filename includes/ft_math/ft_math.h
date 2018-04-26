/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:04:30 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 15:04:30 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "v2i.h"
# include "v2f.h"
# include "v2d.h"
# include "v3i.h"
# include "v3f.h"
# include "v3d.h"
# include "matrix.h"

# define PI 3.14159265358979323846

/*
** Other
*/

float			lerp(const float start, const float end, const float t);
float			map(float input, t_vector2f input_range, t_vector2f output_range);
int				clampi(int min, int max, int val);
float			clampf(float min, float max, float val);
float			rad2deg(float input);

#endif