/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:33:09 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/09 12:13:27 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

static char	*join_free(char *buffer, char *temp)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, temp);
	if (!new_buffer)
		return (NULL);
	free(buffer);
	return (new_buffer);
}

static char	*get_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	long	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		temp[read_bytes] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = join_free(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_buffer(buffer, fd);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	if (!line)
		return (free_and_null(buffer));
	tmp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (!tmp)
		return (free_and_null(line), free_and_null(buffer), NULL);
	free(buffer);
	buffer = tmp;
	return (line);
}
