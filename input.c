/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 13:45:28 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/04/18 14:47:22 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	condition_check(char *argv)
{
	int	i;
	int	period_count;
	int	minus_count;

	i = 0;
	period_count = 0;
	minus_count = 0;
	if (argv[0] == '-')
	{
		minus_count++;
		i++;
	}
	while (argv[i])
	{
		if (argv[i] == '.')
			period_count++;
		if (argv[i] == '-')
			return (EXIT_FAILURE);
		i++;
	}
	if (period_count > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_av1(int argc, char **av)
{
	if (argc != 2 && argc != 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(av[1], "mandelbrot", 12) && ft_strncmp(av[1], "julia", 7))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_input(int argc, char **av)
{
	int	i;
	int	j;

	j = 2;
	if (check_av1(argc, av))
		return (EXIT_FAILURE);
	if (argc == 4)
	{
		while (j < 4)
		{
			if (condition_check(av[j]))
				return (EXIT_FAILURE);
			i = 0;
			while (av[j][i])
			{
				if (ft_isdigit(av[j][i]) || av[j][i] == '.' || av[j][i] == '-')
					i++;
				else
					return (EXIT_FAILURE);
			}
			j++;
		}
	}
	return (EXIT_SUCCESS);
}
