/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:16:10 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/04 14:53:34 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlnbr(int nbr)
{
	int	n;

	n = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		n++;
	}
	if (nbr >= 10)
	{
		n += ft_putlnbr(nbr / 10);
		n += ft_putlnbr(nbr % 10);
	}
	else
		n += ft_putlchar(nbr + 48);
	if (n < 0)
		return (-1);
	return (n);
}
