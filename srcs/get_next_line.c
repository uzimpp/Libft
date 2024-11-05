/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:40:29 by wkullana          #+#    #+#             */
/*   Updated: 2024/11/05 14:08:32 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	clean_lst(t_gnllist **lst)
{
	t_gnllist	*last;
	char		*line;
	int			i;

	if (!lst || !*lst)
		return ;
	last = ft_getlastnode(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	line = ft_strduplen(last->content + i);
	if (!line)
	{
		ft_free_lst(*lst);
		*lst = NULL;
		return ;
	}
	ft_free_lst(*lst);
	*lst = malloc(sizeof(t_gnllist));
	if (!*lst)
		return ((void)free(line));
	(*lst)->content = line;
	(*lst)->next = NULL;
}

void	extract_line(t_gnllist *lst, char **line)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	ft_create_line(line, lst);
	if (!*line)
		return ;
	j = 0;
	while (lst != 0)
	{
		i = 0;
		while (lst->content[i] != 0)
		{
			if (lst->content[i] == '\n')
			{
				(*line)[j++] = lst->content[i];
				break ;
			}
			(*line)[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

int	append(t_gnllist **lst, char *buff, t_gnllist **current, int n)
{
	int			i;
	t_gnllist	*node;

	node = malloc(sizeof(t_gnllist));
	if (!node)
		return (0);
	node->content = malloc(sizeof(char) * (n + 1));
	if (!node->content)
	{
		free(node);
		return (0);
	}
	i = -1;
	while (++i < n)
		node->content[i] = buff[i];
	node->content[i] = '\0';
	node->next = NULL;
	if (!*lst)
		*lst = node;
	else
		(*current)->next = node;
	*current = node;
	return (1);
}

int	readlst(int fd, t_gnllist **lst)
{
	char		*buff;
	int			n;
	t_gnllist	*current;

	n = 1;
	current = *lst;
	while (ft_isnotnewline(current) && n != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		n = (int)read(fd, buff, BUFFER_SIZE);
		if (n == -1 || (!*lst && n == 0))
		{
			free(buff);
			if (n == -1)
				ft_free_lst(*lst);
			return (*lst = NULL, 0);
		}
		buff[n] = '\0';
		if (!append(lst, buff, &current, n))
			return (free(buff), 0);
		free(buff);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnllist	*lst[MAX_FD];
	char				*line;

	if (fd < 0 || MAX_FD <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readlst(fd, &lst[fd]))
		return (ft_free_lst(lst[fd]), lst[fd] = NULL, NULL);
	if (!lst[fd] || !lst[fd]->content)
		return (NULL);
	line = NULL;
	extract_line(lst[fd], &line);
	if (!line)
	{
		ft_free_lst(lst[fd]);
		return (lst[fd] = NULL, NULL);
	}
	clean_lst(&lst[fd]);
	if (!line[0])
	{
		ft_free_lst(lst[fd]);
		return (lst[fd] = NULL, free(line), NULL);
	}
	return (line);
}
