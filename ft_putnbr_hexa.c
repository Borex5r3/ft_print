/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:59:36 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/24 16:41:29 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	somme_hexa(unsigned int n)
{
	int	a;

	a = 1;
	while ((n / 16) != 0)
	{
		n = n / 16;
		a++;
	}
	return (a);
}

static void	put_hexa(unsigned int n)
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

int	ft_putnbr_hexa(unsigned int n)
{
	char			c;
	unsigned int	a;

	a = n;
	while ((n / 16) != 0)
	{
		ft_putnbr_hexa(n / 16);
		n = n % 16;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
		put_hexa(n);
	return (somme_hexa(a));
}
