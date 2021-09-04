#include "fdf.h"

void	rotate_x(t_coordinate *point, t_fdf *data)
{
	float	previous_y;

	previous_y = point->y;
	point->y = previous_y * cos(data->alpha) + point->z * sin(data->alpha);
	point->z = -previous_y * sin(data->alpha) + point->z * cos(data->alpha);
}

void	rotate_y(t_coordinate *point, t_fdf *data)
{
	float	previous_x;

	previous_x = point->x;
	point->x = previous_x * cos(data->beta) + point->z * sin(data->beta);
	point->z = -previous_x * sin(data->beta) + point->z * cos(data->beta);
}

void	rotate_z(t_coordinate *point, t_fdf *data)
{
	float	previous_x;
	float	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = previous_x * cos(data->gamma) - previous_y * sin(data->gamma);
	point->y = previous_x * sin(data->gamma) + previous_y * cos(data->gamma);
}

void	rotate(int key, t_fdf *data)
{
	if (key == 84)
		data->alpha += 0.05;
	else if (key == 91)
		data->alpha -= 0.05;
	else if (key == 86)
		data->beta -= 0.05;
	else if (key == 88)
		data->beta += 0.05;
	else if (key == 83 || key == 85)
		data->gamma += 0.05;
	else if (key == 89 || key == 92)
		data->gamma -= 0.05;
}
