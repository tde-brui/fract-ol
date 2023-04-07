/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 16:05:39 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/07 10:41:51 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_fractol *frac, int i)
{
	return (frac->r * i << 24 | frac->g * i << 16 | frac->b * i << 8 | 250);
}

double	ft_atof(const char *str)
{
	int		i;
	int		minuscounter;
	double	result;

	i = 0;
	minuscounter = 0;
	result = 0;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minuscounter++;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	if (minuscounter % 2 == 1)
		result *= -1;
	return (result);
}

void	menu(t_fractol *fractol)
{
	mlx_put_string(fractol->mlx, "ZOOM IN: SCROLL FORWARD", 800, 30);
	mlx_put_string(fractol->mlx, "ZOOM OUT: SCROLL BACKWARDS", 800, 70);
	mlx_put_string(fractol->mlx, "PYSCHEDELIC: C or X", 800, 110);
	mlx_put_string(fractol->mlx, "ZOOM OUT: SCROLL BACKWARDS", 800, 150);
	mlx_put_string(fractol->mlx, "MOVE SCREEN: arrow keys", 800, 190);
	mlx_put_string(fractol->mlx, "CLOSE WINDOW: ESC", 800, 230);
}
