/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:25:45 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/17 18:00:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	case_delta_lower_than_zero(int *delta, int *increment)
{
	*delta = -*delta;
	*increment = -1;
}

static void	case_slope_lower_than_1(t_data *img, t_point point1, t_point point2,
		t_line_factors br_fac)
{
	int	p;

	if ((point1.u >= 0 && point1.u < WIDTH)
		&& (point1.v >= 0 && point1.v < HEIGHT))
		my_mlx_pixel_put(img, point1.u, point1.v, 0x00FF00FF);
	p = (br_fac.dy * 2) - br_fac.dx;
	while (point1.u != point2.u)
	{
		if (p >= 0)
		{
			point1.v += br_fac.increment_y;
			p -= (br_fac.dx * 2);
		}
		point1.u += br_fac.increment_x;
		p += (br_fac.dy * 2);
		if ((point1.u >= 0 && point1.u < WIDTH)
			&& (point1.v >= 0 && point1.v < HEIGHT))
			my_mlx_pixel_put(img, point1.u, point1.v, 0x00FF00FF);
	}
}

static void	case_slope_higher_than_1(t_data *img, t_point point1,
		t_point point2, t_line_factors br_fac)
{
	int	p;

	if ((point1.u >= 0 && point1.u < WIDTH)
		&& (point1.v >= 0 && point1.v < HEIGHT))
		my_mlx_pixel_put(img, point1.u, point1.v, 0x00660066);
	p = (br_fac.dx * 2) - br_fac.dy;
	while (point1.v != point2.v)
	{
		if (p >= 0)
		{
			point1.u += br_fac.increment_x;
			p -= (br_fac.dy * 2);
		}
		point1.v += br_fac.increment_y;
		p += (br_fac.dx * 2);
		if ((point1.u >= 0 && point1.u < WIDTH)
			&& (point1.v >= 0 && point1.v < HEIGHT))
			my_mlx_pixel_put(img, point1.u, point1.v, 0x00660066);
	}
}

void	bresenham(t_data *img, t_point point1, t_point point2)
{
	t_line_factors	br_fac;

	br_fac.dx = point2.u - point1.u;
	br_fac.dy = point2.v - point1.v;
	br_fac.increment_x = 1;
	br_fac.increment_y = 1;
	if (br_fac.dx < 0)
		case_delta_lower_than_zero(&(br_fac.dx), &(br_fac.increment_x));
	if (br_fac.dy < 0)
		case_delta_lower_than_zero(&(br_fac.dy), &(br_fac.increment_y));
	if (br_fac.dx > br_fac.dy)
		case_slope_lower_than_1(img, point1, point2, br_fac);
	else
		case_slope_higher_than_1(img, point1, point2, br_fac);
}
