/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:07 by frnavarr          #+#    #+#             */
/*   Updated: 2024/11/01 13:13:26 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_filter(char c, va_list *args, int *count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putdir((void *)va_arg(*args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_unsig_putnbr(va_arg(*args, unsigned int)));
	else if (c == 'x')
		ft_puthex((unsigned long long)va_arg(*args, unsigned int), \
			count, false);
	else if (c == 'X')
		ft_puthex((unsigned long long)va_arg(*args, unsigned int), count, true);
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

// int     i; index that traverses the string
// int     j; counter for printed characters
// va_list args; variable to handle the argument list
// va_start(args, s); initializes the argument list
// j = j + ft_putchar(s[i]); prints the normal character

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
			j += ft_putchar(s[i]);
		else
		{
			i++;
			j += ft_conversion_filter(s[i], &args, &j);
		}
		i++;
	}
	va_end(args);
	return (j);
}

/* int   main(void)
{
	void *a;

	a = (void *)42;

    ft_printf("character = %c\n \
	string = %s\n \
	percentage = %%\n \
	n decimal = %d\n \
	integer in base 10 = %i\n \
	unsigned decimal = %u\n \
	lowercase hexadecimal = %x\n \
	uppercase hexadecimal = %X\n \
	*void pointer in hexadecimal = %p\n",
	'j', "Prints",  -161, 4, -45, 123, 123, a);
    
    printf("character = %c\n \
	string = %s\n \
	percentage = %%\n \
	n decimal = %d\n \
	integer in base 10 = %i\n \
	unsigned decimal = %u\n \
	lowercase hexadecimal = %x\n \
	uppercase hexadecimal = %X\n \
	*void pointer in hexadecimal = %p\n", \
	'j', "Prints",  -161, 4, -45, 123, 123, a);
}  */