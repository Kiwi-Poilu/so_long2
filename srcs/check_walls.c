/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:04:50 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:04:51 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_full_row(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i++] != '1')
			return (1);
	}
	return (0);
}

int	check_walls(char *line)
{
	int	i;

	i = 0;
	if (line[i++] != '1')
		return (ft_error_dealer("Map is not surrounded by wall\n"));
	while (line[i + 1])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'X'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != '\n')
			return (ft_error_dealer("Invalid char\n"));
		i++;
	}
	if (line[i] != '1')
		return (ft_error_dealer("Map is not surrounded by walls\n"));
	return (0);
}

int	check_all_walls(t_game *game)
{
	int	i;

	i = 0;
	if (check_full_row(game->map->map[i++]))
		return (ft_error_dealer("Map is not surrounded by walls\n"));
	while (game->map->map[i + 1] != NULL)
	{
		if (ft_strlen(game->map->map[i]) != game->map->width)
			return (ft_error_dealer("Map is not rectangular\n"));
		if (check_walls(game->map->map[i++]))
			return (1);
	}
	if (ft_strlen(game->map->map[i]) != game->map->width)
		return (ft_error_dealer("Map is not rectangular\n"));
	if (check_full_row(game->map->map[i]))
		return (ft_error_dealer("Map is not surrounded by walls\n"));
}
