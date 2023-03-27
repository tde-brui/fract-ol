/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:16:14 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/27 18:35:09 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <unistd.h>

# define HEIGHT 800
# define WIDTH  800
# define MAX_ITERS 80

typedef struct fractol{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			x;
	int			y;
	int			zoom;
}t_fractol;

typedef struct color{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}t_color;

void	background(t_fractol *fractol, int color);
void	mandelbrot(t_fractol *fractol);

#endif
