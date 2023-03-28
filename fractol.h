/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:16:14 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/28 20:08:37 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <unistd.h>

# define HEIGHT 1100
# define WIDTH  1100
# define MAX_ITERS 150

typedef struct fractol{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			zoom;
	int32_t		r;
	int32_t		g;
	int32_t		b;
	int32_t		a;
}t_fractol;

void	background(t_fractol *fractol, int color);
void	mandelbrot(t_fractol *fractol);
int		get_color(t_fractol *frac, int iters);


#endif
