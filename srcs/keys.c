/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:04:41 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:04:42 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	wads_pressed(t_game *game, int keycode)
{
	game->prev_x = game->x;
	game->prev_y = game->y;
	if (keycode == XK_w)
		game->y--;
	if (keycode == XK_a)
	{
		game->direction = 'l';
		game->x--;
	}
	if (keycode == XK_s)
		game->y++;
	if (keycode == XK_d)
	{
		game->direction = 'r';
		game->x++;
	}
	if (game->map->map[game->y][game->x] == '1')
	{
		game->x = game->prev_x;
		game->y = game->prev_y;
	}
	else
		move_player(game);
}

int	button_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_close(game);
	if (keycode == 119 || keycode == 97 || keycode == 100 || keycode == 115)
		wads_pressed(game, keycode);
	return (0);
}
