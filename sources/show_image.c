/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:28:10 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/20 17:26:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

static void	mlx_set_window_and_image(void **mlx, void **win, t_data *img)
{	
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

static int	win_close(int keycode, t_mlx_vars *mlx_vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
		exit(0);
	}
	return (0);
}

void	show_image(t_map_data *map_data)
{
	t_mlx_vars	mlx_vars;
	t_data		img;

	mlx_set_window_and_image(&(mlx_vars.mlx), &(mlx_vars.win), &img);
	put_lines_x(map_data, &img);
	put_lines_y(map_data, &img);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img.img, 0, 0);
	mlx_key_hook(mlx_vars.win, win_close, &mlx_vars);
	mlx_loop(mlx_vars.mlx);
}
