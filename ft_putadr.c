/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:28 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/24 16:37:12 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	somme_hexa(unsigned long n)
{
	int	a;

	a = 3;
	while ((n / 16) != 0)
	{
		n = n / 16;
		a++;
	}
	return (a);
}

static void	put_hexa2(unsigned long n)
{
	if (n == 10)
		write(1, "a", 1);
	if (n == 11)
		write(1, "b", 1);
	if (n == 12)
		write(1, "c", 1);
	if (n == 13)
		write(1, "d", 1);
	if (n == 14)
		write(1, "e", 1);
	if (n == 15)
		write(1, "f", 1);
}

static void	put_hexa(unsigned long n)
{
	char			c;

	while ((n / 16) != 0)
	{
		put_hexa(n / 16);
		n = n % 16;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
		put_hexa2(n);
}

int	ft_putadr(void *p)
{
	unsigned long	a;

	a = (unsigned long)p;
	write(1, "0x", 2);
	put_hexa(a);
	return (somme_hexa(a));
}
