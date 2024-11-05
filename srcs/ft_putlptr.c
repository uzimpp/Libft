/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:16:10 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/13 17:55:51 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putlstr("(nil)"));
	len += ft_putlstr("0x");
	len += ft_putptr(ptr);
	return (len);
}

int	ft_putptr(unsigned long nbr)
{
	unsigned long	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_putptr(nbr / 16);
		len += ft_putptr(nbr % 16);
	}
	else
		len += ft_putlchar("0123456789abcdef"[nbr]);
	return (len);
}
