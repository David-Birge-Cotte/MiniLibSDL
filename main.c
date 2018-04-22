#include "graphics.h"

/*
** This is the main loop
*/
static void			loop(t_app *app)
{
	handle_event(app);
	//calculate_frame(app); // fractal dont need refresh
	sdl_draw(app->sdl, app->pixels);
}

/*
** The entry point of the program
*/
int					main()
{
	t_app		*app;

	app = new_app();
	apply_fnc_to_each_pixel(app->pixels, &draw_frac);
	while (app->loop)
		loop(app);
	app_del(app);
	return (0);
}