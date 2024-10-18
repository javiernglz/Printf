/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:07 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/18 17:29:03 by frnavarr         ###   ########.fr       */
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
	else if (c == 'p')
		return (ft_putdir(va_arg(*args, unsigned long)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned long long, int *, bool false)));
	else if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned long long, int, bool true)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

//	int		i; indice que recorre la cadena
//	int		j; contador de caracteres impresos
// va_list args; variable para manejar la lista de argumentos
// va_start(args, s); inicializa la lista de argumentos
// j = j + ft_putchar(s[i]); imprime el carácter normal

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
	ft_printf("my name is 100% %s and the letter %c is my fav.\n", "Juan", 'A');
	return (0);
}
