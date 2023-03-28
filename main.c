/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:24:52 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/28 20:35:35 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	init_fractol(t_fractol	*data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol window", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	data->zoom = 1;
	data->r = 2;
	data->g = 4;
	data->b = 6;
	data->a = 250;
	return (EXIT_SUCCESS);
}

void	ft_scroll(double delta_x, double delta_y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	delta_x = 0;
	if (delta_y > 0)
		fractol->zoom *= 1.1;
	else if (delta_y < 0)
		fractol->zoom *= 0.9;
}

void	ft_hook(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->image->instances[0].x += 5;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->image->instances[0].x -= 5;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->image->instances[0].y += 5;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->image->instances[0].y -= 5;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_C))
	{
		fractol->r += 2;
		fractol->g += 2;
		fractol->b += 2;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_X))
	{
		fractol->r -= 2;
		fractol->g -= 2;
		fractol->b -= 2;
	}
}

int	main(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		exit(1);
	init_fractol(fractol);
	mandelbrot(fractol);
	mlx_loop_hook(fractol->mlx, ft_hook, fractol);
	mlx_scroll_hook(fractol->mlx, ft_scroll, fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
	return (EXIT_SUCCESS);
}
