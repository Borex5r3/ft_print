/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:01:22 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/24 16:39:19 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	somme_bexa(unsigned int n)
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

static void	put_bexa(unsigned int n)
{
	if (n == 10)
		write(1, "A", 1);
	if (n == 11)
		write(1, "B", 1);
	if (n == 12)
		write(1, "C", 1);
	if (n == 13)
		write(1, "D", 1);
	if (n == 14)
		write(1, "E", 1);
	if (n == 15)
		write(1, "F", 1);
}

int	ft_putnbr_bexa(unsigned int n)
{
	char			c;
	unsigned int	a;

	a = n;
	while ((n / 16) != 0)
	{
		ft_putnbr_bexa(n / 16);
		n = n % 16;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
		put_bexa(n);
	return (somme_bexa(a));
}
