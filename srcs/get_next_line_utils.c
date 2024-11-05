/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:40:29 by wkullana          #+#    #+#             */
/*   Updated: 2024/11/05 13:16:30 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_isnotnewline(t_list *current)
{
	char	*content;

	if (!current)
		return (1);
	content = current->content;
	while (*content)
	{
		if (*content == '\n')
			return (0);
		content++;
	}
	return (1);
}

t_list	*ft_getlastnode(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	ft_create_line(char **line, t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	ft_free_lst(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

char	*ft_strduplen(char *s1)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (s1[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
