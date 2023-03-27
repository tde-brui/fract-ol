/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:33:53 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/02/08 17:19:22 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*printf_min_int(char *str)
{
	char	*lol;
	int		i;

	i = 0;
	lol = "-2147483648";
	while (lol[i])
	{
		str[i] = lol[i];
		i++;
	}
	return (str);
}

char	*printf_itoa(int n)
{
	char	*ptr;
	int		j;

	j = printf_len(n);
	ptr = (char *)malloc(printf_len(n) + 1);
	if (ptr == 0)
		return (0);
	ptr[j] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		ptr[j - 1] = (n % 10) + 48;
		j--;
		n = n / 10;
	}
	if (n > -1 && n < 10)
		ptr[j - 1] = n + 48;
	if (n == -2147483648)
		ptr = printf_min_int(ptr);
	return (ptr);
}

int	ft_get_int(int n)
{
	char	*ptr;

	ptr = printf_itoa(n);
	printf_putstr(ptr);
	free(ptr);
	return (printf_len(n));
}
