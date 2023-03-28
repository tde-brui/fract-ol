/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 16:05:39 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/03/28 19:08:16 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_fractol *frac, int i)
{
	return (frac->r * i << 24 | frac->g * i << 16 | frac->b * i << 8 | 250);
}
