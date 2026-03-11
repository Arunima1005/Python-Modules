/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:32:19 by archowdh          #+#    #+#             */
/*   Updated: 2026/03/11 15:36:14 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower( int c);
int			ft_toupper(int c);
size_t		strlen(const char *s);
size_t		strlcpy(char *dst, const char *src, size_t size);
int 		ft_atoi(const char *nptr);
void		*ft_bzero(void *s, size_t n);

#endif