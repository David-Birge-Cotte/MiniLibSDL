/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:44:01 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/03 13:44:02 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

static t_3dobject	obj_new(t_objtype type, t_color diff_color,
							t_matrix transform, intersect inter)
{
	t_3dobject	obj;

	obj.type = type;
	obj.mat.diffuse = diff_color;
	obj.transform = transform;
	obj.inter = inter;
	return (obj);
}

/*
** Creates a simple scene with a rotate box and a sphere
*/

static t_scene		scene_01(void)
{
	t_scene		scene;

	scene.nb_obj = 6;
	scene.objs = ft_memalloc(sizeof(t_3dobject) * scene.nb_obj);
	scene.objs[0] = obj_new(SPHERE, to_color(BLUE), m_mult(m_translate(
			v3d(0, 0, 0)), m_scale(v3d(1, 0, 0))), &sphere_intersect);
	scene.objs[1] = obj_new(SPHERE, to_color(BLUE), m_mult(m_translate(
			v3d(-50, 0, 0)), m_scale(v3d(45, 0, 0))), &sphere_intersect);
	scene.objs[2] = obj_new(SPHERE, to_color(RED), m_mult(m_translate(
			v3d(50, 0, 0)), m_scale(v3d(45, 0, 0))), &sphere_intersect);
	scene.objs[3] = obj_new(SPHERE, to_color(GREEN), m_mult(m_translate(
			v3d(0, 0, 50)), m_scale(v3d(45, 0, 0))), &sphere_intersect);
	scene.objs[4] = obj_new(SPHERE, to_color(WHITE), m_mult(m_translate(
			v3d(0, -3, 0)), m_scale(v3d(3, 0, 0))), &sphere_intersect);
	scene.objs[5] = obj_new(SPHERE, to_color(WHITE), m_mult(m_translate(
			v3d(-1, 1, -1)), m_scale(v3d(1, 0, 0))), &sphere_intersect);
	scene.lights = ft_memalloc(sizeof(t_light));
	scene.nb_lights = 1;
	scene.lights[0].intensity = 1;
	scene.lights[0].pos = v3d(-5, 20, -10);
	scene.camera.transform = m_mult(m_translate(v3d(0, 0, -10)),
									m_rotate(v3d(0, 0, 0)));
	return (scene);
}

t_scene			new_scene(void)
{
	return (scene_01());
}
