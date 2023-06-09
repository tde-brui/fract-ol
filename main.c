/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:24:52 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/18 14:32:53 by tde-brui      ########   odam.nl         */
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
	data->offset_x = 2;
	data->offset_y = 2;
	data->r = 2;
	data->g = 4;
	data->b = 6;
	data->jul_x = 0;
	data->jul_y = 0;
	return (EXIT_SUCCESS);
}

int	init_sign(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 12))
		fractol->sign = 0;
	else if (argc == 2 && !ft_strncmp(argv[1], "julia", 7))
		fractol->sign = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 7))
	{
		fractol->sign = 1;
		fractol->jul_x = ft_atof(argv[2]);
		fractol->jul_y = ft_atof(argv[3]);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (check_input(argc, argv))
	{
		write(1, "Valid parameters are:\nmandelbrot\njulia (x, y)\n", 47);
		exit(EXIT_FAILURE);
	}
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		exit(EXIT_FAILURE);
	init_fractol(fractol);
	if (init_sign(argc, argv, fractol))
		return (EXIT_FAILURE);
	ft_hooks(fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
	return (EXIT_SUCCESS);
}
