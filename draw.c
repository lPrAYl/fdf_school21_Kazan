#include "fdf.h"
#include <math.h>
#include <stdio.h>

#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)(y)][(int)(x)];
	z1 = data->z_matrix[(int)(y1)][(int)(x1)];

	//---------zoom--------------------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//---------color-------------------
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	//----------3D---------------------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//--------shift--------------------
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

// void	coordinates_init(coordinates *xyz)
// {
// 	x = 0;
// 	y = 0;
// 	x1 = 0;
// 	y1 = 0;
// }

void	draw(fdf *data)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if(x < data->width - 1)
			{
				bresenham(x, y, x + 1, y, data);
			}
			if(y < data->height - 1)
			{
				bresenham(x, y, x, y + 1, data);
			}
			x++;
		}
		y++;
	}
}