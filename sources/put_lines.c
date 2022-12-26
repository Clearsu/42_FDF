/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:13:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/14 14:10:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_lines_x(t_map_data *map_data, t_data *img)
{
	size_t	row_len;
	size_t	col_len;
	size_t	i;
	size_t	j;

	row_len = map_data->row_len;
	col_len = map_data->col_len - 1;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			bresenham(img, map_data->point[i][j], map_data->point[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	put_lines_y(t_map_data *map_data, t_data *img)
{
	size_t	row_len;
	size_t	col_len;
	size_t	i;
	size_t	j;

	row_len = map_data->row_len - 1;
	col_len = map_data->col_len;
	j = 0;
	while (j < col_len)
	{
		i = 0;
		while (i < row_len)
		{
			bresenham(img, map_data->point[i][j], map_data->point[i + 1][j]);
			i++;
		}
		j++;
	}
}
