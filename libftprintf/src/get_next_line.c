/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:17:13 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/21 13:53:16 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_sub(char **rest, char **line)
{
	char	*str;

	str = NULL;
	if (*rest)
	{
		*line = *rest;
		str = ft_strchr(*rest, '\n');
		if (str)
		{
			str++;
			if (*str != '\0')
				*rest = ft_strdup(str);
			else
				*rest = NULL;
			*str = '\0';
		}
		else
			*rest = NULL;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		*line[0] = '\0';
	}
	return (str);
}

char	*ft_sub_2(char **rest, char **line, char **buf)
{
	char	*str;
	char	*tmp;

	str = ft_strchr(*buf, '\n');
	if (str)
	{
		str++;
		if (*str != '\0')
			*rest = ft_strdup(str);
		*str = '\0';
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			i;
	char		*str;
	static char	*rest[1024];
	char		*line;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	str = ft_sub(&rest[fd], &line);
	i = 1;
	while (!str && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		str = ft_sub_2(&rest[fd], &line, &buf);
	}
	free(buf);
	if (ft_strlen(line) > 0)
		return (line);
	free (line);
	return (NULL);
}
