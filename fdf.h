/*
**	--------------- program structure ---------------
**	1. read file
**		- get height(how many lines) of text
**		- get width(how many numbers of line)
**		- allocate memory for **int by using width and height (look your ft_strsplit())
**		- read file and write number int **int matrix by using ft_strsplit() and ft_atoi()
**	---------------
**	2. drawing line function (google Bresenham algoritm)
**		- find by how much we need to increase x and by how much we need to increase y
**			by using float. Example:
**				x = 2; x1 = 4;
**				y = 2; y1 = 6;
**				steps for x: 2
**				steps for y: 4
**				that means that y should grow 2 times faster than x
**				every loop step: y += 1 and x += 0.5
**				after 4 steps x and y will be equal with x1, y1
**							real x:y			x:y				pixels
**				start		2.0 : 2.0			2:2					.
**				step1		2.5 : 3.0			2:3					.
**				step2		3.0 : 4.0			3:4					 .
**				step3		3.5 : 5.0			3:5					 .
**				step4		4.0 : 6.0			4:6					  .
**
**				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
** ---------------
** 3. function which draws lines between every dot
**		- example:
**				0->		0->		0->		0
**				|		|		|		|
**
**				0->		10->	10->	0
**				|		|		|		|
**
**				0->		10->	10->	0
**				|		|		|		|
**
**				0->		0->		0->		0
**			'->' and '|' are lines between dots
**			every dot has two lines (right and down):	0->
**														|
** ---------------
** 4. adding 3D
**		- change cordinatates by using isometric formulas:
**			x' = (x- y) * cos(angle);
**			y' = (x + y) * sin(angle) - z;
**		- x' and y' are coordinates in 3D format (default angle 0.8)
** ---------------
** 5. adding bonuses (move, rotatin, zoom)
**		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**			call the func. deal_key.
**		- in the deal_key func. you have to change some parametrs, clear the window with
**			mlx_clear_window(mlx_ptr, win_ptr) and redraw the picture
** 6. error handling
**		- check if argc ==2
**		- check if file exists: if((fd = open(file_name, O_RDONLY) > 0)
** ---------------
** 7. fix leaks
**		- type leaks a.out or leaks fdf int your shell
*/

#ifndef FDF_H
# define FDF_H

# include <fcntl.h> 
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct 
{
	int	width;
	int	height;
	int	**z_matrix;
	int	zoom;
	int	color;
	int	shift_x;
	int	shift_y;

	

	void	*mlx_ptr;
	void	*win_ptr;
}				fdf;

typedef	struct 
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				coordinates;


void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif

