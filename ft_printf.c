/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:07 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/17 19:20:36 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//funcion putchar pero que cuente hasta que encuentre un %.
//variadicas
//funcion filtro de %s %c %i ... buscara el sig. elemento
int	ft_conversion_filter(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	//else if (c == 'i')
	//	return (ft_putnbr(va_arg(*args, int)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
			j = j + ft_putchar(s[i]);
		else
		{
			i++;
			ft_conversion_filter(s[i], &args);
		}
		i++;
	}
	va_end(args);
	return (j);
}

int	main(void)
{
	ft_printf("my name is %s and the letter %c is my fav.\n", "Juan", 'A');
	return (0);
}
