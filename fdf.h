#ifndef FDF_H
# define FDF_H

# include <fcntl.h> 
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>
# include "minilibx_macos/mlx.h"

typedef struct s_coordinate
{
	float	x;
	float	y;
	float	z;
}				t_coordinate;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	int		iso;
	int		zoom;
	float	zoom_x;
	float	zoom_y;
	float	zoom_z;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	int		color;
	int		shift_x;
	int		shift_y;
	double	alpha;
	double	beta;
	double	gamma;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*xpm_data;
	int		bits_per_pixel;
	int		lenght_line;
	int		endian;
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
void	my_pixel_put(t_coordinate point, t_fdf *data);

int		ft_close(void);
void	init_image(t_fdf *data);
int		deal_key(int key, t_fdf *data);
int		mouse_button(int key, int x, int y, t_fdf *data);

void	rotate_x(t_coordinate *point, t_fdf *data);
void	rotate_y(t_coordinate *point, t_fdf *data);
void	rotate_z(t_coordinate *point, t_fdf *data);
void	rotate(int key, t_fdf *data);

#endif
