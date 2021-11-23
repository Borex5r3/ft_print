/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:16:26 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/23 11:32:23 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	somme(unsigned int n)
{
	int	s;

	s = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

int	ft_putnbr_base(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_base((n / 10));
		ft_putnbr_base((n % 10));
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
	return (somme(n));
}
