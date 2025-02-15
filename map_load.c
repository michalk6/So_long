/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:41:50 by mikurek           #+#    #+#             */
/*   Updated: 2025/02/15 17:01:05 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static int	ft_open_map_src(char *map_src)
{
	int	fd;

	fd = open(map_src, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open map");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static size_t	ft_get_height(int fd)
{
	size_t	height;
	char	*line;

	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return (height);
}

static size_t	ft_validate_width(char **content)
{
	size_t	width;

	width = ft_strlen(*content);
	while (*content)
	{
		if (width != ft_strlen(*content))
		{
			write(2, "Invalid map\n", 13);
			return (0);
		}
		content++;
	}
	return (width);
}

static char	**ft_get_content(int height, int fd)
{
	char	**content;
	int		i;
	int		j;

	content = malloc((height + 1) * sizeof(char *));
	if (content == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		content[i] = get_next_line(fd);
		if (!content[i])
			break ;
		while (content[i][j])
		{
			if (content[i][j] == '\n')
				content[i][j] = 0;
			j++;
		}
		i++;
	}
	content[i] = NULL;
	return (content);
}

t_map	*ft_load_map(char *map_src)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	fd = ft_open_map_src(map_src);
	map->height = ft_get_height(fd);
	fd = ft_open_map_src(map_src);
	map->content = ft_get_content(map->height, fd);
	map->width = ft_validate_width(map->content);
	close(fd);
	if (map->width == 0)
	{
		free_map(map);
		return (NULL);
	}
	if (!ft_check_rules(map))
	{
		free_map(map);
		ft_printf("map loading filed\n");
		return (NULL);
	}
	return (map);
}
