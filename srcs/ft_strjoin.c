/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:42:18 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:24:58 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	start = res;
	while (*s1)
		*(res++) = *(s1++);
	while (*s2)
		*(res++) = *(s2++);
	*res = '\0';
	return (start);
}
