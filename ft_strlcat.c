/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:30:48 by wkullana          #+#    #+#             */
/*   Updated: 2024/08/29 13:25:14 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (!dst && size == 0)
		return (len_s);
	len_d = ft_strlen(dst);
	if (len_d >= size)
		return (size + len_s);
	if (len_s < size - len_d)
		ft_memcpy(dst + len_d, src, len_s + 1);
	else
	{
		ft_memcpy(dst + len_d, src, size - len_d - 1);
		dst[size - 1] = '\0';
	}
	return (len_d + len_s);
}
