/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:32 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/23 13:03:48 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar_fd(int a);
int	ft_putstr_fd(char *p);
int	ft_putnbr_fd(int c);
int	ft_putnbr_base(unsigned int n);
int	ft_putnbr_hexa(unsigned int n);
int	ft_putnbr_bexa(unsigned int n);

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int	i;
	int	a;

	i = 0;
	a = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				a = a + ft_putchar_fd(va_arg(ptr, int));
			else if (format[i + 1] == 's')
				a = a + ft_putstr_fd(va_arg(ptr, char *));
			else if (format[i + 1] == 'd' || 
					format[i + 1] == 'i')
				a = a + ft_putnbr_fd(va_arg(ptr, int));
			else if (format[i + 1] == 'u')
				a = a + ft_putnbr_base(va_arg(ptr, unsigned int));
			else if (format[i + 1] == 'x')
				a = a + ft_putnbr_hexa(va_arg(ptr, unsigned int));
			else if (format[i + 1] == 'X')
				a = a + ft_putnbr_bexa(va_arg(ptr, unsigned int));
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				a++;
			}
		}
		i++;
	}
	va_end(ptr);
	return (a);
}

int main()
{
	int	a = ft_printf("%X", 42);
	printf("%d", a);
}
