/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:31:07 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 16:31:07 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

static void	draw_tris(t_uint32 *pixels, t_vector3d tri, t_vector3d *vertex)
{
	draw_line(pixels, v2i(vertex[(int)tri.x].x, vertex[(int)tri.x].y),
						v2i(vertex[(int)tri.y].x, vertex[(int)tri.y].y), new_color(WHITE));
	draw_line(pixels, v2i(vertex[(int)tri.y].x, vertex[(int)tri.y].y),
						v2i(vertex[(int)tri.z].x, vertex[(int)tri.z].y), new_color(WHITE));
	draw_line(pixels, v2i(vertex[(int)tri.z].x, vertex[(int)tri.z].y),
						v2i(vertex[(int)tri.x].x, vertex[(int)tri.x].y), new_color(WHITE));
}

void	draw_mesh(t_uint32 *pixels, t_mesh mesh)
{
	size_t	i;

	i = 0;
	while (i < mesh.nb_tris)
	{
		draw_tris(pixels, mesh.trianges[i], mesh.vertex);
		i++;
	}
}

t_mesh	*create_box(size_t size_x, size_t size_y, size_t size_z)
{
	t_mesh	*mesh;

	mesh = ft_memalloc(sizeof(t_mesh));
	mesh->vertex = ft_memalloc(sizeof(t_vector3d) * 8);
	mesh->trianges = ft_memalloc(sizeof(t_vector3d) * 12);
	mesh->nb_tris = 12;

	// all vertices
	mesh->vertex[0] = v3d(0, 0, 0);
	mesh->vertex[1] = v3d(size_x, 0, 0);
	mesh->vertex[2] = v3d(size_x, size_y, 0);
	mesh->vertex[3] = v3d(0, size_y, 0);
	mesh->vertex[4] = v3d(0, 0, size_z);
	mesh->vertex[5] = v3d(size_x, 0, size_z);
	mesh->vertex[6] = v3d(size_x, size_y, size_z);
	mesh->vertex[7] = v3d(0, size_y, size_z);

	// front
	mesh->trianges[0] = v3d(0, 1, 3);
	mesh->trianges[1] = v3d(2, 1, 3);

	// left
	mesh->trianges[2] = v3d(0, 3, 4);
	mesh->trianges[3] = v3d(7, 3, 4);

	// back
	mesh->trianges[4] = v3d(4, 7, 5);
	mesh->trianges[5] = v3d(6, 7, 5);

	// right
	mesh->trianges[6] = v3d(6, 5, 2);
	mesh->trianges[7] = v3d(1, 5, 2);

	// top
	mesh->trianges[8] = v3d(3, 7, 2);
	mesh->trianges[9] = v3d(6, 7, 2);

	// bottom
	mesh->trianges[10] = v3d(4, 0, 5);
	mesh->trianges[11] = v3d(1, 0, 5);

	return (mesh);
}

t_color	*noise(t_uint32 x, t_uint32 y, t_app *app)
{
	t_color		*color;
	static t_uint32	seed = 42;
	t_uint32		rng;

	seed++;
	rng = rand_r(&seed);
	color = new_color(rng, rng, rng, 255);
	return (color);
}
