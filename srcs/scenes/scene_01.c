#include "../../includes/graphics.h"

/*
** Creates a simple scene with a rotate box and a sphere
*/
static t_scene scene_01()
{
	t_scene		scene;
	t_3dobject	box;
	t_3dobject	sphere;

	box.type = MESH;
	box.mesh = create_box(5, 5, 2);
	box.transform = m_translate(v3d(0, 0, 5));
	sphere.type = SPHERE;
	sphere.transform = m_translate(v3d(3, 1, 0));
	scene.nb_obj = 2;
	scene.objs = ft_memalloc(sizeof(t_3dobject) * scene.nb_obj);
	scene.objs[0] = box;
	scene.objs[1] = sphere;
	scene.lights = ft_memalloc(sizeof(t_light));
	scene.nb_lights = 1;
	return (scene);
}

t_scene			new_scene()
{
	return(scene_01());
}