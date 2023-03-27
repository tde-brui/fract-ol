/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-brui <tde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 18:10:59 by tde-brui      #+#    #+#                 */
/*   Updated: 2023/02/08 17:18:33 by tde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>

int			ft_unsigned_dec(unsigned int num);
int			ft_get_int(int n);
int			printf_putstr(char *str);
int			ft_printf(const char *str, ...);
int			printf_putchar(int c);
int			ft_lower_hexa(unsigned int n);
int			ft_upper_hexa(unsigned int n);
int			ft_hexa_len(unsigned int n);
int			ft_put_addr(void *ptr);

#endif