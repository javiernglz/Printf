/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:43 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/25 13:34:44 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
	}
	count = count + ft_putchar(n % 10) + '0';
	return (count);
}

int	ft_putdir(unsigned long n)
{
	int				count;
	char			*hexa;
	unsigned long	last_dig;

	hexa = "0123456789abcdef";
	last_dig = n % 16;
	count = 0;
	if (n == 0)
	{
		return (write(1, "0x0", 3));
	}
	if (n >= 16)
		count = ft_putdir(n / 16);
	write(1, &hexa[last_dig], 1);
	return (count + 1);
}

//convertimos los digitos mayores que 9 (son abcdef) mediante ascii
// 'A' es 65, 'A' - 10 es 55
// 'a' es 97, 'a' - 10 es 87
int	ft_puthex(unsigned long long n, int *count, bool caps)
{
	char	conver_dig;
	int		res;

	res = 0;
	if (caps)
		conver_dig = 'A' - 10;
	else
		conver_dig = 'a' - 10;
	if (n >= 16)
	{
		res = ft_puthex(n / 16, count, caps);
		res = ft_puthex(n % 16, count, caps);
	}
	else
	{
		if (n < 10)
			conver_dig = n + '0';
		else
			conver_dig = n + conver_dig;
		*count = *count + write(1, &conver_dig, 1);
		res++;
	}
	return (res);
}
