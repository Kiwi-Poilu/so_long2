/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:02:54 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:05:52 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	gnl_proxy(int fd, char **line)
{
	int	ret;
	int	i;

	ret = get_next_line(fd, line);
	if (ret < 0)
	{
		free(*line);
		return (-1);
	}
	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == ' ')
		{
			free(*line);
			while (get_next_line(fd, line) > 0)
				free(*line);
			free(*line);
			ft_error_dealer("Invalid char\n");
			return (-2);
		}
		++i;
	}
	return (ret);
}

char	**ft_store_map_free(char *a, char*b, int ret_gnl)
{
	free(a);
	free(b);
	if (ret_gnl != -2)
		ft_putstr("Erreur lors de la lecture du fichier\n");
	return (NULL);
}

char	**ft_store_map(int fd)
{
	int		ret_gnl;
	char	**map;
	char	*line;
	char	*tmp;
	char	*ttmp;

	ret_gnl = 1;
	tmp = NULL;
	line = NULL;
	while (ret_gnl)
	{
		ret_gnl = gnl_proxy(fd, &line);
		if (ret_gnl < 0)
			return (ft_store_map_free(tmp, NULL, ret_gnl));
		ttmp = ft_strjoin(tmp, line);
		if (ttmp == NULL)
			return (ft_store_map_free(line, ttmp, -2));
		tmp = ft_strjoin(ttmp, " ");
		if (tmp == NULL)
			return (ft_store_map_free(NULL, ttmp, -2));
		free(line);
	}
	map = ft_split(tmp, ' ');
	free(tmp);
	return (map);
}

int	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
		free(game->map->map[i++]);
	free(game->map->map);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_game	game;

	if (ac != 2)
		return (ft_error_dealer("Wrong number of arguments\n"));
	if (ft_check_ber(av[1]) != 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error_dealer("Could not open map\n"));
	map.map = ft_store_map(fd);
	close(fd);
	if (map.map == NULL)
		return (1);
	game.map = &map;
	if (parsing(&game) != 0)
		return (ft_free_map(&game));
	ft_game(&map, &game);
}
