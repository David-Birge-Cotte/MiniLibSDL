/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_allocator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:38:14 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/17 10:38:14 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

t_3dobject	obj_new(t_color diff_color,
							t_vector3d pos, t_vector3d rot,
							t_bool (*inter)(const t_ray ray,
								const t_3dobject obj, t_hit_data *hit))
{
	t_3dobject	obj;

	obj.mat.diffuse = diff_color;
	obj.mat.specular = 0.2f;
	obj.pos = pos;
	obj.rot = v3d_unit(rot);
	obj.inter = inter;
	return (obj);
}

int			add_light_to_scene(t_scene *scene, char *line)
{
	t_vector3d	*v3ds;

	if ((v3ds = extract_vectors(line)) == NULL)
		return (-1);
	scene->light.pos = v3ds[0];
	scene->light.intensity = 1;
	ft_memdel((void**)&v3ds);
	return (1);
}

int			add_cam_to_scene(t_scene *scene, char *line)
{
	t_vector3d	*v3ds;

	if ((v3ds = extract_vectors(line)) == NULL)
		return (-1);
	scene->camera.pos = v3ds[0];
	scene->camera.rot = v3ds[1];
	ft_memdel((void**)&v3ds);
	return (1);
}

static int	add_cyl_cone(t_scene *scene, char *line, size_t i_obj,
						t_vector3d *v3ds)
{
	if (ft_strncmp(line, "CYLINDER:", 9) == 0)
	{
		scene->objs[i_obj] = obj_new(
			to_color(v3ds[2].x, v3ds[2].y, v3ds[2].z, 255),
			v3ds[0], v3ds[1], &cylinder_intersect);
	}
	else if (ft_strncmp(line, "CONE:", 5) == 0)
	{
		scene->objs[i_obj] = obj_new(
			to_color(v3ds[2].x, v3ds[2].y, v3ds[2].z, 255),
			v3ds[0], v3ds[1], &cone_intersect);
	}
	else
		return (-1);
	return (1);
}

int			add_obj_to_scene(t_scene *scene, char *line, size_t i_obj)
{
	t_vector3d	*v3ds;

	if ((v3ds = extract_vectors(line)) == NULL)
		return (-1);
	if (ft_strncmp(line, "SPHERE:", 7) == 0)
	{
		scene->objs[i_obj] = obj_new(
			to_color(v3ds[2].x, v3ds[2].y, v3ds[2].z, 255),
			v3ds[0], v3ds[1], &sphere_intersect);
	}
	else if (ft_strncmp(line, "PLANE:", 6) == 0)
	{
		scene->objs[i_obj] = obj_new(
			to_color(v3ds[2].x, v3ds[2].y, v3ds[2].z, 255),
			v3ds[0], v3ds[1], &plane_intersect);
	}
	else if (add_cyl_cone(scene, line, i_obj, v3ds) < 0)
		return (-1);
	ft_memdel((void**)&v3ds);
	return (1);
}
