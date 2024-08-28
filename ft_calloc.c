/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:36:02 by wkullana          #+#    #+#             */
/*   Updated: 2024/08/28 23:24:12 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			n;

	n = count * size;
	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < n)
		tmp[i++] = 0;
	return (tmp);
}
