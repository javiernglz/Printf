/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:43 by frnavarr          #+#    #+#             */
/*   Updated: 2024/11/01 13:10:09 by frnavarr         ###   ########.fr       */
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
		count += ft_putnbr(n / 10);
	}
	count = count + ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putdir(void *s)
{
	int	count;

	if (!s)
		return (write(1, "(nil)", 5));
	count = 0;
	count = count + write(1, "0x", 2);
	ft_puthex((unsigned long long)s, &count, false);
	return (count);
}

// we convert digits greater than 9 (which are abcdef) using ASCII
// 'A' is 65, 'A' - 10 is 55
// 'a' is 97, 'a' - 10 is 87

void	ft_puthex(unsigned long long n, int *count, bool caps)
{
	int	conver_dig;

	if (caps)
		conver_dig = 'A' - 10;
	else
		conver_dig = 'a' - 10;
	if (n >= 16)
	{
		ft_puthex(n / 16, count, caps);
		ft_puthex(n % 16, count, caps);
	}
	else
	{
		if (n < 10)
			n = n + '0';
		else
			n += conver_dig;
		*count += write(1, &n, 1);
	}
}
