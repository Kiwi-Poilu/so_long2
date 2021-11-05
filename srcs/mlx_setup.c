/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:04:30 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:04:32 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_fill_struct(t_game *game, t_map *map, t_mlx *mlx)
{
	game->move = 0;
	game->mlx = mlx;
	game->map = map;
	game->direction = 'r';
	mlx->mlx = mlx_init();
	ft_null_xpm(mlx);
	if (mlx->mlx == NULL)
	{
		ft_error_dealer("mlx_init() failed\n");
		ft_close(game);
	}
	if (ft_init_xpm(mlx) == 1)
		ft_close(game);
	return (0);
}

void	ft_destroy_image(void *mlx, void *xpm)
{
	if (xpm != NULL)
		mlx_destroy_image(mlx, xpm);
}

int	ft_close(t_game *game)
{
	int	i;

	i = 0;
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_plb);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_plw);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_prb);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_prw);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_black);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_white);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_fw);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_fb);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_exit_black);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_exit_white);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_wall);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_ennemy_black);
	ft_destroy_image(game->mlx->mlx, game->mlx->xpm_ennemy_white);
	if (game->mlx->win != NULL)
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	if (game->mlx->mlx != NULL)
		mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	while (game->map->map[i])
		free(game->map->map[i++]);
	free(game->map->map);
	exit(0);
}
