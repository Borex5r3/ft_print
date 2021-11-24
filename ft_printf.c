/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:32 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/24 12:32:27 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	printini(va_list ptr, const char *format, int i, int *a)
{
	if (format[i + 1] == 'c')
		*a = *a + ft_putchar_fd(va_arg(ptr, int));
	else if (format[i + 1] == 's')
		*a = *a + ft_putstr_fd(va_arg(ptr, char *));
	else if (format[i + 1] == 'p')
		*a = *a + ft_putadr(va_arg(ptr, void *));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		*a = *a + ft_putnbr_fd(va_arg(ptr, int));
	else if (format[i + 1] == 'u')
		*a = *a + ft_putnbr_base(va_arg(ptr, unsigned int));
	else if (format[i + 1] == 'x')
		*a = *a + ft_putnbr_hexa(va_arg(ptr, unsigned int));
	else if (format[i + 1] == 'X')
		*a = *a + ft_putnbr_bexa(va_arg(ptr, unsigned int));
	else
		*a = *a + ft_putchar_fd(format[i + 1]);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!(format))
		return (a + ft_putstr_fd("(null)"));
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printini(ptr, format, i, &a);
			i++;
		}
		else
			a = a + ft_putchar_fd(format[i]);
		i++;
	}
	va_end(ptr);
	return (a);
}
