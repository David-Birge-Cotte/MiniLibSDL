/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:28:44 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/05/17 09:28:45 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

t_vector3d	extract_vector(char *vector)
{
	char	*a;
	char	*b;

	if (vector == NULL)
		return (v3d(0, 0, 0));
	a = ft_strchr(vector, ',') + 1;
	if (a == NULL)
		return (v3d(0, 0, 0));
	b = ft_strchr(a, ',') + 1;
	if (b == NULL)
		return (v3d(0, 0, 0));
	return (v3d(ft_atoi(vector), ft_atoi(a), ft_atoi(b)));
}

t_vector3d	*extract_vectors(char *line)
{
	char		*part;
	t_vector3d	*v3ds;
	size_t		i;
	size_t		v;

	i = 0;
	v = 0;
	while (line[i++])
		v += (line[i] == ';' ? 1 : 0);
	if (v == 0 || (v3ds = ft_memalloc(sizeof(t_vector3d) * v)) == NULL)
		return (NULL);
	i = 0;
	if ((part = ft_strchr(line, ':') + 1) == NULL)
		return (NULL);
	while (part[i++])
		if (part[i - 1] != ',' && part[i - 1] != '-' && part[i - 1] != ';'
			&& (part[i - 1] > '9' || part[i - 1] < '0') && part[i - 1] != ' ')
			return (NULL);
	i = 0;
	while (i < v)
	{
		v3ds[i++] = extract_vector(part);
		part = ft_strchr(part, ';') + 1;
	}
	return (v3ds);
}

static int	create_scene(t_scene *scene, int fd)
{
	char		*line;
	t_vector3d	*v3ds;
	size_t		i_obj;

	if ((scene->objs =
		ft_memalloc(sizeof(t_3dobject) * scene->nb_obj)) == NULL)
		return (-1);
	i_obj = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "CAMERA:", 7) == 0)
		{
			if (add_cam_to_scene(scene, line) < 0)
				return (-1);
		}
		else if (ft_strncmp(line, "LIGHT:", 6) == 0)
		{
			if (add_light_to_scene(scene, line) < 0)
				return (-1);
		}
		else if (add_obj_to_scene(scene, line, i_obj++) < 0)
			return (-1);
		ft_strdel(&line);
	}
	return (1);
}

static int	get_num_line(char *file)
{
	char	*line;
	size_t	nb_lines;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nb_lines++;
	}
	ft_strdel(&line);
	if (close(fd))
		return (-1);
	return (nb_lines);
}

int			load_scene(char *file, t_app *app)
{
	t_scene	scene;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	scene.nb_obj = get_num_line(file) - 2;
	if (create_scene(&scene, fd) < 0)
		return (-1);
	if (close(fd))
		return (-1);
	app->scene = scene;
	return (1);
}
