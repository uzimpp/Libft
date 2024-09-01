/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:43:11 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:23:13 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_d;
	char	*tmp_s;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp_d = (char *) dst;
	tmp_s = (char *) src;
	i = 0;
	if (tmp_d > tmp_s)
		while (len-- > 0)
			tmp_d[len] = tmp_s[len];
	else
	{
		while (i < len)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	return (dst);
}
