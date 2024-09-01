/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:09:33 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:24:07 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	par;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	par = 1;
	if (*str == '-')
	{
		par *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (48 <= *str && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * par);
}
