#include "fdf.h"

int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

void	my_pixel_put(t_coordinate point, t_fdf *data)
{
	char	*dst;
	int		x;
	int		y;

	x = (int)point.x;
	y = (int)point.y;
	if (x > 0 && x < 1920)
	{
		if (y > 0 && y < 1200)
		{
			dst = data->xpm_data + (y * data->lenght_line \
						+ x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = data->color;
		}
	}
}

void	init_image(t_fdf *data)
{
	data->zoom = 50;
	data->zoom_x = 1;
	data->zoom_y = 1;
	data->zoom_z = 1;
	data->iso = 1;
	data->shift_x = 960;
	data->shift_y = 400;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		ft_error("Wrong number of arguments");
	read_file(argv[1], &data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_error("Malloc error");
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1200, "FDF");
	init_image(&data);
	draw(&data);
	mlx_hook(data.win_ptr, 2, 0, deal_key, &data);
	mlx_hook(data.win_ptr, 4, 0, mouse_button, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
