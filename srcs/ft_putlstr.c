/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:16:10 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/04 14:53:42 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putlstr(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (ft_putlstr("(null)"));
	while (*s != '\0')
	{
		if (ft_putlchar(*s++) == -1)
			return (-1);
		n++;
	}
	return (n);
}
