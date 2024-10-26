/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:09:13 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/26 11:06:02 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsig_putnbr(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_unsig_putnbr(n / 10);
		count += ft_unsig_putnbr(n % 10);
	}
	else
	{
		digit = n + 48;
		write(1, &digit, 1);
		count++;
	}
	return (count);
}
