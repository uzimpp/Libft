/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:25:50 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:25:22 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long ln)
{
	int	len;

	len = 1;
	if (ln < 0)
	{
		len++;
		ln = -ln;
	}
	while (ln >= 10)
	{
		len++;
		ln /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	ln;

	ln = n;
	len = ft_intlen(ln);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (ln < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
		res[0] = 48;
	while (ln > 0)
	{
		res[--len] = (ln % 10) + 48;
		ln /= 10;
	}
	return (res);
}
