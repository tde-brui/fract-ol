/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:16:14 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/07 10:41:43 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <unistd.h>

# define HEIGHT 1100
# define WIDTH  1100
# define MAX_ITERS 100

typedef struct fractol{
	mlx_t		*mlx;
	mlx_image_t	*image;
	float		zoom;
	int32_t		r;
	int32_t		g;
	int32_t		b;
	float		offset_x;
	float		offset_y;
	float		jul_x;
	float		jul_y;
	int			sign;
}t_fractol;

void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);

// Hooks
void	ft_scroll(double delta_x, double delta_y, void *param);
void	ft_key(void *param);
void	ft_hook(void *param);
void	ft_hooks(t_fractol *fractol);

// Util functions
int		get_color(t_fractol *frac, int iters);
double	ft_atof(const char *str);
void	menu(t_fractol *fractol);

#endif
