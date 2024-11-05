/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbrbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:16:10 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/09 19:54:50 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlnbrbase(unsigned int nbr, char *base, unsigned int len)
{
	int	n;

	n = 0;
	if (!nbr)
		return (ft_putlchar('0'));
	if (nbr >= len)
	{
		n += ft_putlnbrbase(nbr / len, base, len);
		n += ft_putlnbrbase(nbr % len, base, len);
	}
	else
		n += ft_putlchar(base[nbr]);
	if (n < 0)
		return (-1);
	return (n);
}
