#include "graphics.h"

float	clampf(float min, float max, float val)
{
	float ret;

	ret = val;
	if (val > max) ret = max;
	else if (val < min) ret = min;
	return (ret);
}

int		clampi(int min, int max, int val)
{
	int ret;

	ret = val;
	if (val > max) ret = max;
	else if (val < min) ret = min;
	return (ret);
}