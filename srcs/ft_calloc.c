/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:36:02 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/04 10:42:33 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			n;

	n = count * size;
	if ((long) count == 0 || (long) size == 0)
		n = 1;
	else if ((long) count < 0 || (long) size < 0)
		return (NULL);
	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
