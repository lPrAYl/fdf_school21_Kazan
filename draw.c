#include "fdf.h"

static void	isometric(t_coordinate *point)
{
	point->x = (point->x - point->y) * cos(3.1415 / 3);
	point->y = (point->x + point->y) * sin(3.1415 / 6) - point->z;
}

static void	location(t_coordinate *start, t_coordinate *end, t_fdf *data)
{
	if (data->zoom < 1)
		data->zoom = 1;
	start->x *= data->zoom * data->zoom_x;
	start->y *= data->zoom * data->zoom_y;
	end->x *= data->zoom * data->zoom_x;
	end->y *= data->zoom * data->zoom_y;
	rotate_x(start, data), rotate_x(end, data);
	rotate_y(start, data), rotate_y(end, data);
	rotate_z(start, data), rotate_z(end, data);
	if (data->iso == 1)
		isometric(start), isometric(end);
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

static void	bresenham(t_coordinate start, t_coordinate end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	start.z = data->z_matrix[(int)start.y][(int)start.x] * data->zoom_z;
	end.z = data->z_matrix[(int)end.y][(int)end.x] * data->zoom_z;
	if (data->zoom_z == 0)
		data->zoom_z = 0.000001;
	if (start.z || end.z)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	location(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{		
		my_pixel_put(start, data);
		start.x += x_step;
		start.y += y_step;
	}
}

static void	draw_line(t_coordinate *start, t_coordinate *end, t_fdf *data)
{
	if ((*start).x < data->width - 1)
	{
		(*end).x = (*start).x + 1;
		(*end).y = (*start).y;
		bresenham(*start, *end, data);
	}
	if ((*start).y < data->height - 1)
	{
		(*end).x = (*start).x;
		(*end).y = (*start).y + 1;
		bresenham(*start, *end, data);
	}
}

void	draw(t_fdf *data)
{
	t_coordinate	start;
	t_coordinate	end;

	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1200);
	data->xpm_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
										&data->lenght_line, &data->endian);
	start.y = 0;
	while (start.y < data->height)
	{
		start.x = 0;
		while (start.x < data->width)
		{
			draw_line(&start, &end, data);
			start.x++;
		}
		start.y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
