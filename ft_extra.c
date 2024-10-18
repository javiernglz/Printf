/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:43 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/18 13:38:14 by frnavarr         ###   ########.fr       */
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
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	digit;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			digit = n + 48;
			write(1, &digit, 1);
		}
	}
	return (digit);
}

int	ft_putdir(unsigned long n)
{
	char			*hexa;
	unsigned long	last_dig;

	hexa = "0123456789abcdef";
	last_dig = n % 16;
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (NULL);
	}

	if (n >= 16)
		ft_putdir(n / 16);
	write(1, &hexa[last_dig], 1);
}
