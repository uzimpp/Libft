/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:58:36 by wkullana          #+#    #+#             */
/*   Updated: 2024/11/05 14:11:16 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_gnllist
{
	char				*content;
	struct s_gnllist	*next;
}	t_gnllist;

char		*get_next_line(int fd);
int			readlst(int fd, t_gnllist **lst);
int			append(t_gnllist **lst, char *buff, t_gnllist **current, int n);
void		clean_lst(t_gnllist **lst);
void		extract_line(t_gnllist *lst, char **line);

int			ft_isnotnewline(t_gnllist *current);
t_gnllist	*ft_getlastnode(t_gnllist *lst);
void		ft_create_line(char **line, t_gnllist *lst);
void		ft_free_lst(t_gnllist *lst);
char		*ft_strduplen(char *s1);

#endif