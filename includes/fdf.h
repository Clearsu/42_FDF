/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:12:19 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/16 14:58:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "macro.h"
# include "libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	u;
	int	v;
}	t_point;

typedef struct s_raw_map
{
	char	***map_str;
	size_t	row_len;
	size_t	col_len;
}	t_raw_map;

typedef struct s_map_data
{
	t_point		**point;
	size_t		row_len;
	size_t		col_len;
}	t_map_data;

typedef struct s_line_factors
{
	int	dx;
	int	dy;
	int	increment_x;
	int	increment_y;
}	t_line_factors;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}	t_mlx_vars;

typedef struct s_boundary_vals
{
	int	x_min;
	int	y_min;
	int	x_max;
	int	y_max;
}	t_boundary_vals;

void	is_valid_map(t_raw_map *raw_map);
void	read_and_save(t_raw_map *raw_map, char *argv);
void	put_map_data(t_raw_map *raw_map, t_map_data *map_data);
void	error(size_t n);
void	show_image(t_map_data *map_data);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	put_lines_x(t_map_data *map_data, t_data *img);
void	put_lines_y(t_map_data *map_data, t_data *img);
void	rotate_map(t_map_data *map_data, size_t row_len, size_t col_len);
void	iso_projection(t_map_data *map_data);
void	bresenham(t_data *img, t_point point1, t_point point2);
void	adjust_center(t_map_data *map_data);
void	argument_check(int argc);
void	free_splitted_line(char **ptr);

#endif
