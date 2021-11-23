/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:16:59 by adbaich           #+#    #+#             */
/*   Updated: 2021/11/23 19:27:17 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar_fd(int a);
int	ft_putstr_fd(char *p);
int	ft_putnbr_fd(int c);
int	ft_putnbr_base(unsigned int n);
int	ft_putnbr_hexa(unsigned int n);
int	ft_putnbr_bexa(unsigned int n);
int	ft_putadr(void *p);
int	ft_printf(const char *format, ...);



#endif
