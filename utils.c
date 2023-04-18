/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 16:05:39 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/14 16:55:37 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_fractol *frac, int i)
{
	return (frac->r * i << 24 | frac->g * i << 16 | frac->b * i << 8 | 250);
}

int	determine_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

double	ft_atof(const char *str)
{
	int		i;
	double	value;
	double	power;
	int		sign;

	i = 0;
	value = 0.0;
	power = 1;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = determine_sign(str[i++]);
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		power *= 10;
		i++;
	}
	return (sign * value / power);
}

void	menu(t_fractol *fractol)
{
	mlx_put_string(fractol->mlx, "ZOOM IN: SCROLL FORWARD", WIDTH - 300, 30);
	mlx_put_string(fractol->mlx, "ZOOM OUT: SCROLL BACKWARDS", WIDTH - 300, 70);
	mlx_put_string(fractol->mlx, "PYSCHEDELIC: C or X", WIDTH - 300, 110);
	mlx_put_string(fractol->mlx, "ZOOM OUT: SCROLL BACKWARD", WIDTH - 300, 150);
	mlx_put_string(fractol->mlx, "MOVE SCREEN: arrow keys", WIDTH - 300, 190);
	mlx_put_string(fractol->mlx, "CLOSE WINDOW: ESC", WIDTH - 300, 230);
	mlx_put_string(fractol->mlx, "MOVE JULIA SET: J and K", WIDTH - 300, 270);
}
