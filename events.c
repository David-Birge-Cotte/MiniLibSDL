#include "graphics.h"

static void	keydown(t_app *app, int keycode)
{
	if(keycode == SDLK_ESCAPE)
		app->loop = FALSE;
}

/*
** Listens to event and responds to them
*/
void	handle_event(t_app *app)
{
	SDL_Event	*event;

	event = app->sdl->event;
	SDL_WaitEvent(event);
	switch (event->type)
	{
		case SDL_QUIT:
			app->loop = FALSE;
			break;
		case SDL_KEYDOWN:
			keydown(app, event->key.keysym.sym);
			break;
	}
}