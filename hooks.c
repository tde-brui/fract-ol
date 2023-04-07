/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 14:40:29 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/07 10:51:56 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scroll(double delta_x, double delta_y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (delta_y > 0)
		fractol->zoom *= 0.9;
	else if (delta_y < 0)
		fractol->zoom *= 1.1;
	delta_x = 0;
}

void	ft_key(void *param)
{
	t_fractol	*fractol;

	fractol = param;
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

void	ft_hook(void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->offset_x += 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->offset_x -= 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->offset_y += 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->offset_y -= 0.1;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_J))
		fractol->jul_x += 0.05;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_K))
		fractol->jul_x -= 0.05;
	if (fractol->sign == 0)
		mandelbrot(fractol);
	if (fractol->sign == 1)
		julia(fractol);
}

void	ft_hooks(t_fractol *fractol)
{
	menu(fractol);
	mlx_loop_hook(fractol->mlx, ft_hook, fractol);
	mlx_loop_hook(fractol->mlx, ft_key, fractol);
	mlx_scroll_hook(fractol->mlx, ft_scroll, fractol);
}
