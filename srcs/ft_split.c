/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:09:21 by wkullana          #+#    #+#             */
/*   Updated: 2024/09/01 12:25:17 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*word;

	start = *s;
	len = 0;
	while (**s != c && **s)
	{
		(*s)++;
		len++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (len > 0)
	{
		len--;
		word[len] = start[len];
	}
	word[*s - start] = '\0';
	return (word);
}

static void	*ft_free_split(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	res = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i] = extract_word(&s, c);
			if (!res[i])
				return (ft_free_split(res, i));
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
