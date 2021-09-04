#include "fdf.h"

void	move(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
}

void	zoom_axis(int key, t_fdf *data)
{
	if (key == 2)
		data->zoom_x += 0.05;
	if (key == 0 && data->zoom_x > 0)
		data->zoom_x -= 0.05;
	if (key == 1)
		data->zoom_y += 0.05;
	if (key == 13 && data->zoom_y > 0)
		data->zoom_y -= 0.05;
	if (key == 115)
		data->zoom_z += 1;
	if (key == 119)
		data->zoom_z -= 1;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 8 || key == 87)
		init_image(data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, data);
	if (key == 0 || key == 2 || key == 13 || key == 1
		|| key == 115 || key == 119)
		zoom_axis(key, data);
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 83 || key == 84 || key == 85 || key == 86
		|| key == 88 || key == 89 || key == 91 || key == 92)
		rotate(key, data);
	if (key == 35)
		data->iso = 0;
	if (key == 34)
		data->iso = 1;
	if (key == 53)
		ft_close();
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	mouse_button(int key, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (key == 4)
		data->zoom += 1;
	if (key == 5)
		data->zoom -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
