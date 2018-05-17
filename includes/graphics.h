/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:27:21 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:27:23 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

/*
** Required libraries
*/
# include <OpenCL/cl.h>
# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include "ft_math/ft_math.h"

/*
** Window settings
*/
# define WIN_WIDTH (512)
# define WIN_HEIGHT (512)
# define WIN_TITLE "RT v1"
# define CAM_FOV (60)
# define AMBIANT (0.2f)
# define MOVE_SPEED (0.2f)
# define TURN_SPEED (2)

/*
** Easy access simple colors RGBA8888
*/
# define WHITE	255	, 255	, 255	, 255
# define RED	255	, 0		, 0		, 255
# define GREEN	0	, 255	, 0		, 255
# define BLUE	0	, 0		, 255	, 255
# define BLACK	0	, 0		, 0		, 255
# define TRANSP	0	, 0		, 0		, 0

/*
** 32 bit color structure RGBA8888
*/

typedef struct		s_color
{
	t_uint8			r;
	t_uint8			g;
	t_uint8			b;
	t_uint8			a;
}					t_color;

/*
** Ray used for Ray-casting / Ray*trcing
*/

typedef struct		s_ray
{
	t_vector3d		pos;
	t_vector3d		dir;
}					t_ray;

/*
** Light object
*/

typedef struct		s_light
{
	t_vector3d		pos;
	float			intensity;
}					t_light;

/*
** Material for objects
*/

typedef struct		s_mat
{
	t_color			diffuse;
	float			specular;
}					t_mat;
/*
** 3D object with a transform in world space
** the mesh pointer is null unless type == MESH
*/

typedef struct		s_hit_data
{
	t_vector3d		pos;
	t_vector3d		normal;
	t_mat			mat;
	double			t1;
	double			t2;
}					t_hit_data;

/*
** Intersection function pointer
*/

//typedef t_bool	(*t_intersect)(const t_ray ray, const t_3dobject obj,
//							t_hit_data *hit);

/*
** Main object struct
** transform	-> 4x4 transformation matrix
** type			-> primitive type
** mat			-> material data
** intersec		-> function pointer for computing ray-intersection
*/

typedef struct		s_3dobject
{
	t_vector3d		pos;
	t_vector3d		rot;
	t_mat			mat;
	t_bool			(*inter)(const t_ray ray, const struct s_3dobject obj,
							t_hit_data *hit);
}					t_3dobject;

/*
** Simple camera with a transform and a projection matrix
*/

typedef struct		s_camera
{
	t_vector3d		pos;
	t_vector3d		rot;
}					t_camera;

/*
** Simple scene with one camera and some 3D objects
*/

typedef struct		s_scene
{
	t_camera		camera;
	t_light			light;
	t_3dobject		*objs;
	size_t			nb_obj;
}					t_scene;

/*
** Contains the bare minimum for communicating with the SDL library
*/

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*frame;
	SDL_Event		*event;
}					t_sdl;

/*
** App structure instantiated in main()
*/

typedef struct		s_app
{
	t_bool			loop;
	t_uint32		*pixels;
	size_t			nb_pixels;
	t_sdl			*sdl;
	t_scene			scene;
}					t_app;

/*
** Arg used for multithreading
*/

typedef struct		s_multit_arg
{
	t_uint32		y_min;
	t_uint32		y_max;
	t_app			*app;
	t_color			(*fnc_ptr)(t_uint32, t_uint32, t_app *app);
}					t_multit_arg;

/*
** Colors
*/

t_uint32			color_to_pixeldata(const t_color *color);
t_color				*new_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color				to_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color				*add_to_color(t_color *original,
						const t_color *color_to_add);
t_color				*lerp_color(const t_color *start, const t_color *end,
						float t);
t_color				color_mult(const t_color color, const float m);

/*
** Events
*/

void				handle_event(t_app *app);

/*
** Multithreading
*/

void				threader(t_multit_arg arg);

/*
** Ray Tracing
*/

t_color				ray_trace(t_uint32 x, t_uint32 y, t_app *app);
t_ray				ray_from_cam(t_camera cam, t_uint32 x, t_uint32 y);
t_ray				new_ray(t_vector3d pos, t_vector3d dir);

/*
** Primitive intersection
*/

t_bool				plane_intersect(const t_ray ray,
						const t_3dobject obj, t_hit_data *hit);
t_bool				sphere_intersect(const t_ray ray,
						const t_3dobject obj, t_hit_data *hit);
t_bool				cone_intersect(const t_ray ray,
						const t_3dobject obj, t_hit_data *hit);
t_bool				cylinder_intersect(const t_ray ray,
						const t_3dobject obj, t_hit_data *hit);

/*
** Draw
*/

void				calculate_frame(t_app *app);
void				apply_fnc_to_each_pixel(t_app *app,
						t_color (*fnc_ptr)(t_uint32 x, t_uint32 y, t_app *app));
void				fill_frame(t_uint32 *pixels, size_t nb_pixels,
						t_color color);
int					display(t_sdl *sdl, t_uint32 *pixels);
void				put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y,
						const t_color *color);
void				draw_line(t_uint32 *pixels, t_vector2i p1, t_vector2i p2,
						const t_color *color);
t_color				*draw_frac(t_uint32 x, t_uint32 y);
t_color				noise(t_uint32 x, t_uint32 y, t_app *app);

/*
** App & SDL
*/

t_app				*new_app(void);
void				app_del(t_app *app);
t_sdl				*new_sdl(void);
void				sdl_del(t_sdl *sdl);
void				quit_app(void);

/*
** Fractal (use for test with apply_fnc_to_each_pixel())
*/

t_color				*draw_frac(t_uint32 x, t_uint32 y);

/*
** Scenes
*/

int					load_scene(char *file, t_app *app);
t_scene				new_scene();
t_3dobject			obj_new(t_color diff_color,
							t_vector3d pos, t_vector3d rot,
							t_bool (*inter)(const t_ray ray, const t_3dobject obj, t_hit_data *hit));
t_vector3d			extract_vector(char *vector);
t_vector3d			*extract_vectors(char *line);
int					add_obj_to_scene(t_scene *scene, char *line, size_t i_obj);
int					add_cam_to_scene(t_scene *scene, char *line);
int					add_light_to_scene(t_scene *scene, char *line);

#endif
