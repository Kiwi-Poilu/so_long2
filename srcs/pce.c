/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pce.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:06:03 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:06:25 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_val_pce(int pce[3])
{
	if (pce[0] != 1)
		return (ft_error_dealer("Player number is different than one\n"));
	if (pce[1] < 1)
		return (ft_error_dealer("No food on the map\n"));
	if (pce[2] < 1)
		return (ft_error_dealer("The map has no exit\n"));
	return (0);
}

void	check_pce_line(int i, t_game *game, int pce[3])
{
	int	j;

	j = 0;
	while (game->map->map[i][j])
	{
		if (game->map->map[i][j] == 'P')
		{
			game->map->map[i][j] = '0';
			pce[0]++;
			game->x = j;
			game->y = i;
		}
		if (game->map->map[i][j] == 'C')
			pce[1]++;
		if (game->map->map[i][j] == 'E')
			pce[2]++;
		j++;
	}
}

int	check_pce(t_game *game)
{
	int	i;
	int	j;
	int	pce[3];

	i = 0;
	pce[0] = 0;
	pce[1] = 0;
	pce[2] = 0;
	while (game->map->map[i + 1] != NULL)
	{
		check_pce_line(i, game, pce);
		i++;
	}
	return (ft_val_pce(pce));
}
