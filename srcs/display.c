/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:13:07 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/05 18:13:08 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_player(t_game *game, int i, int j)
{
	if (i % 2 == j % 2)
	{
		if (game->direction == 'r')
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_prb, j * 64, i * 64);
		else
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_plb, j * 64, i * 64);
	}
	else
	{
		if (game->direction == 'r')
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_prw, j * 64, i * 64);
		else
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_plw, j * 64, i * 64);
	}
}

void	display_food(t_game *game, int i, int j)
{
	if (i % 2 == j % 2)
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_fb, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_fw, j * 64, i * 64);
}

void	display_ennemy(t_game *game, int i, int j)
{
	if (i % 2 == j % 2)
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_ennemy_black, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_ennemy_white, j * 64, i * 64);
}

void	display_exit(t_game *game, int i, int j)
{
	if (i % 2 == j % 2)
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_exit_black, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_exit_white, j * 64, i * 64);
}
