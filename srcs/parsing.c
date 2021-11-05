/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:43:14 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 18:43:16 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_ber(char *str)
{
	int		i;
	int		j;
	char	*ber;

	ber = "reb.";
	i = 0;
	j = 0;
	if (ft_strlen(str) < 5)
		return (ft_error_dealer("Not a .ber file\n"));
	while (str[i])
		i++;
	while (ber[j])
	{
		i--;
		if (ber[j] != str[i])
			return (ft_error_dealer("Not a .ber file\n"));
		j++;
	}
	return (0);
}

int	ft_error_dealer(char *error)
{
	ft_putstr("Error\n");
	ft_putstr(error);
	return (1);
}

int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	set_width_height(t_game *game)
{
	game->map->width = ft_strlen(game->map->map[0]);
	game->map->height = ft_map_height(game->map->map);
	if (game->map->height < 1)
		return (ft_error_dealer("Empty map\n"));
	return (0);
}

int	parsing(t_game *game)
{
	if (set_width_height(game))
		return (1);
	if (check_all_walls(game))
		return (1);
	if (check_pce(game))
		return (1);
	return (0);
}
