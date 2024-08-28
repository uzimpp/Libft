/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:34:01 by wkullana          #+#    #+#             */
/*   Updated: 2024/08/28 23:27:34 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (dst == NULL && src == NULL)
		return (dst);
	tmp_d = (unsigned char *) dst;
	tmp_s = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_d++) = *(tmp_s++);
		n--;
	}
	return (dst);
}
