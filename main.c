/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:24:52 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/27 18:42:57 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol	*data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "FdF window", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}

int	main(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->zoom = 20;
	init_fractol(fractol);
	mandelbrot(fractol);
	mlx_loop(fractol->mlx);
}
