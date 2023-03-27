/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:15:49 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/27 18:43:03 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	get_iters(float x, float y)
{
	float	im;
	float	real;
	float	real_temp;
	int		iter;

	im = y;
	real = x;
	iter = 0;
	while (iter < MAX_ITERS && (real * real - im * im) < 4)
	{
		real_temp = real * real - im * im + x;
		im = 2 * real * im + y;
		real = real_temp;
		iter++;
	}
	return (iter);
}

// int	get_color(int iters, int max_iters)
// {
// 	double	f;
// 	t_color	color;

// 	f = iters / max_iters;
// 	color.r = (unsigned char)(255 * f);
// 	color.g = (unsigned char)(255 * (1 - f));
// 	color.b = 0;
// }

void	mandelbrot(t_fractol *fractol)
{
	float	y;
	float	x;
	float	x2;
	float	y2;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			x2 = x / WIDTH * 4 - 2;
			y2 = y / HEIGHT * 4 - 2;
			iter = get_iters(x2, y2);
			if (iter == MAX_ITERS)
				mlx_put_pixel(fractol->image, x, y, 0XFF000000);
			else
				mlx_put_pixel(fractol->image, x, y, 0XFFFFFFFF);
			x++;
		}
		y++;
	}
}
