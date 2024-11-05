/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:58:36 by wkullana          #+#    #+#             */
/*   Updated: 2024/11/05 13:14:36 by wkullana         ###   ########.fr       */
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

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		readlst(int fd, t_list **lst);
int		append(t_list **lst, char *buff, t_list **current, int n);
void	clean_lst(t_list **lst);
void	extract_line(t_list *lst, char **line);

int		ft_isnotnewline(t_list *current);
t_list	*ft_getlastnode(t_list *lst);
void	ft_create_line(char **line, t_list *lst);
void	ft_free_lst(t_list *lst);
char	*ft_strduplen(char *s1);

#endif