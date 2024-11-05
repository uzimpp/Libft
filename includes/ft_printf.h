/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkullana <wkullana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:37:15 by wkullana          #+#    #+#             */
/*   Updated: 2024/10/06 17:07:53 by wkullana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Main functions
int	ft_printf(const char *s, ...);
int	ft_option(char c, va_list *ap);
int	ft_format(const char *s, va_list *ap);

// Helper functions
int	ft_putlptr(unsigned long ptr);
int	ft_putptr(unsigned long nbr);
int	ft_putlchar(char c);
int	ft_putlstr(char *s);
int	ft_putlnbr(int nbr);
int	ft_putlnbrbase(unsigned int nbr, char *base, unsigned int len);

#endif