/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:28:36 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/17 07:55:54 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_option(char c, va_list *ap)
{
	int	n;

	n = 0;
	if (c == 'c')
		n += ft_putlchar(va_arg(*ap, int));
	else if (c == 's')
		n += ft_putlstr(va_arg(*ap, char *));
	else if (c == 'p')
		n += ft_putlptr(va_arg(*ap, unsigned long));
	else if (c == 'd' || c == 'i')
		n += ft_putlnbr(va_arg(*ap, int));
	else if (c == 'u')
		n += ft_putlnbrbase(va_arg(*ap, unsigned int), "0123456789", 10);
	else if (c == 'x')
		n += ft_putlnbrbase(va_arg(*ap, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		n += ft_putlnbrbase(va_arg(*ap, unsigned int), "0123456789ABCDEF", 16);
	else if (c == '%')
		n += ft_putlchar('%');
	else
		return (-1);
	return (n);
}

int	ft_format(const char *s, va_list *ap)
{
	int	n;
	int	tmp;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			tmp = ft_option(s[++i], ap);
			if (tmp == -1)
				return (-1);
			n += tmp;
		}
		else
		{
			if (ft_putlchar(s[i]) == -1)
				return (-1);
			n++;
		}
		i++;
	}
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		n;

	n = 0;
	va_start(ap, s);
	n += ft_format(s, &ap);
	va_end(ap);
	return (n);
}
