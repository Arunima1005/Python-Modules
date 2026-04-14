/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archowdh <archowdh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:51:17 by archowdh          #+#    #+#             */
/*   Updated: 2026/04/14 20:32:09 by archowdh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *ft_get_line(char *buffer)
{
	int	len;
	char	*line;

	if (!*buffer)
		return (NULL);
	if (ft_strchr(buffer, '\n'))
		len = ft_strchr(buffer, '\n') - buffer + 1;
	else
		len = ft_strlen(buffer);
	line = ft_strndup(buffer, len);
	return (line);
}

static char *ft_new_stash(char *stash)
{
	char	*new_stash;
	char	*newline_ptr;

	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
	{
		free(stash);
		return (NULL);
	}
	newline_ptr++;
	new_stash = ft_strndup(newline_ptr, ft_strlen(newline_ptr));
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}
static char	*ft_read_file(int fd, char *stash)
{
	char	*new_stash;
	char	*tmp;
	int		bytes;

	new_stash = malloc(BUFFER_SIZE + 1);
	if (!new_stash)
		return (free(stash), NULL);
	while (1)
	{
		bytes = read(fd, new_stash, BUFFER_SIZE);
		if (bytes == -1)
			return (free(new_stash), free(stash), NULL);
		if (bytes == 0)
			break ;
		new_stash[bytes] = '\0';
		tmp = ft_strjoin(stash, new_stash);
		free(stash);
		stash = tmp;
		if (!stash)
			return (free(new_stash), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(new_stash);
	return (stash);
}
char *get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_new_stash(stash[fd]);
	return (line);
}
