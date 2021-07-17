/*
** --------------- 3D ---------------------------------------------
**		x' = (x - y) * cos(angle);
**		y' = (x + y) * sin(angle) - z;
** ----------------------------------------------------------------
** --------- mlx_function usage -----------------------------------
**		void *mlx_ptr;
**		void *win_ptr;
**
**		mlx_ptr = mlx_init();
**		win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, int(y), #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
** ----------------------------------------------------------------
** --------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data)
** ----------------------------------------------------------------
** colors:
**		white = 0xffffff
**		red = 0xe80c0c
** ----------------------------------------------------------------
** frameworks:
**	-framework OpenGL -framework AppKit;
*/

#include "fdf.h"
#include "ft_printf/ft_print.h"
int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

int	deal_key(int key, fdf *data)
{
	ft_printf("%d\n", key);

	if(key == 126)
		data->shift_y -= 10;
	if(key == 125)
		data->shift_y += 10;
	if(key == 123)
		data->shift_x -= 10;
	if(key == 124)
		data->shift_x += 10;
	if(key == 53)
		ft_close();
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}


int	main(int argc, char **argv)
{
	// int	i;
	// int	j;
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);


	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 50;
	draw(data);
	//bresenham(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	
	mlx_loop(data->mlx_ptr);

	// i = 0;
	// while (i < data->height)
	// {
	// 	j = 0;
	// 	while (j < data->width)
	// 	{
	// 		ft_printf("%3d", data->z_matrix[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }


	return (0);
}