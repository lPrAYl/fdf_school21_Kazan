#include "fdf.h"

static unsigned int	ft_count_substr(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count_substr;

	if (!s)
		return (0);
	count_substr = 0;
	i = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i))
			i++;
		if (*(s + i) != c && *(s + i))
			count_substr++;
		while (*(s + i) != c && *(s + i))
			i++;
	}
	return (count_substr);
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_count_substr(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	int		i;
	char	**nums;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	if (ft_strncmp(&file_name[ft_strlen(file_name) - 4], ".fdf", 4))
		ft_error("Wrong name file");
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error(NULL);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int **) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int *) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line))
		fill_matrix(data->z_matrix[i++], line), free(line);
	free(line);
	close(fd);
	free (data->z_matrix[i]);
	data->z_matrix[i] = NULL;
}
