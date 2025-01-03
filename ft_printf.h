/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:51:25 by frnavarr          #+#    #+#             */
/*   Updated: 2024/11/15 12:15:22 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

int		ft_printf(char const *s, ...);
int		ft_conversion_filter(char c, va_list *args, int *count);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putdir(void *s);
int		ft_unsig_putnbr(unsigned int n);
void	ft_puthex(unsigned long long n, int *count, bool caps);

#endif