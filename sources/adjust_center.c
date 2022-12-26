/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:51:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/14 14:20:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_boundary_vals(t_map_data *map_data,
		t_boundary_vals *boundary_vals, size_t row_len, size_t col_len)
{
	size_t	i;
	size_t	j;
	int		y_max;
	int		y_min;

	boundary_vals->x_min = map_data->point[row_len - 1][0].u;
	boundary_vals->x_max = map_data->point[0][col_len - 1].u;
	y_max = map_data->point[0][0].v;
	y_min = map_data->point[0][0].v;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			if (y_max < map_data->point[i][j].v)
				y_max = map_data->point[i][j].v;
			if (y_min > map_data->point[i][j].v)
				y_min = map_data->point[i][j].v;
			j++;
		}
		i++;
	}
	boundary_vals->y_min = y_min;
	boundary_vals->y_max = y_max;
}

static void	add_delta(t_map_data *map_data, t_boundary_vals boundary_vals,
		size_t row_len, size_t col_len)
{
	size_t	i;
	size_t	j;
	int		width_space;
	int		height_space;

	width_space = (WIDTH - (boundary_vals.x_max - boundary_vals.x_min)) / 2
		- boundary_vals.x_min;
	height_space = (HEIGHT - (boundary_vals.y_max - boundary_vals.y_min)) / 2
		- boundary_vals.y_min;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			map_data->point[i][j].u += width_space;
			map_data->point[i][j].v += height_space;
			j++;
		}
		i++;
	}
}

void	adjust_center(t_map_data *map_data)
{
	size_t			row_len;
	size_t			col_len;
	t_boundary_vals	boundary_vals;

	row_len = map_data->row_len;
	col_len = map_data->col_len;
	get_boundary_vals(map_data, &boundary_vals, row_len, col_len);
	add_delta(map_data, boundary_vals, row_len, col_len);
}
