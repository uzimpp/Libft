/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:07:56 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:23:48 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*res;

	cc = (char) c;
	res = NULL;
	while (*s)
	{
		if (*s == cc)
			res = (char *) &*s;
		s++;
	}
	if (*s == cc)
		res = (char *) &*s;
	return (res);
}
