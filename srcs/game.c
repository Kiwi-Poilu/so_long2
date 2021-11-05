/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:00:44 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/04 23:03:45 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_food(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_tile(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->xpm_wall, j * 64, i * 64);
	if (c == 'P')
		display_player(game, i, j);
	if (c == '0')
	{
		if (i % 2 == j % 2)
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_black, j * 64, i * 64);
		else
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->mlx->xpm_white, j * 64, i * 64);
	}
	if (c == 'C')
		display_food(game, i, j);
	if (c == 'E')
		display_exit(game, i, j);
	if (c == 'X')
		display_ennemy(game, i, j);
}

int	ft_draw(t_game	*game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			if (x == game->y && y == game->x)
				ft_tile(game, 'P', x, y);
			else
				ft_tile(game, game->map->map[x][y], x, y);
			y++;
		}
		x++;
	}
	return (0);
}

void	move_player(t_game *game)
{
	game->move++;
	if (game->map->map[game->y][game->x] == 'C')
		game->map->map[game->y][game->x] = '0';
	ft_tile(game, game->map->map[game->prev_y][game->prev_x],
		game->prev_y, game->prev_x);
	ft_tile(game, 'P', game->y, game->x);
	ft_tile(game, '1', 0, 0);
	game->str_move = ft_itoa(game->move);
	mlx_string_put(game->mlx->mlx, game->mlx->win,
		32, 36, 0xFFFFFFFF, game->str_move);
	free(game->str_move);
	if (game->map->map[game->y][game->x] == 'X')
	{
		ft_putstr("You lost :C\n");
		ft_close(game);
	}
	if (game->map->map[game->y][game->x] == 'E' && ft_check_food(game) == 0)
	{
		printf("Congratulations, you won in %d moves\n", game->move);
		ft_close(game);
	}
}

int	ft_game(t_map *map, t_game *game)
{
	t_mlx	mlx;
	int		vertical_res;
	int		horizontal_res;

	mlx.win = NULL;
	ft_fill_struct(game, map, &mlx);
	vertical_res = map->width * 64;
	horizontal_res = map->height * 64;
	mlx.win = mlx_new_window(mlx.mlx, vertical_res, horizontal_res, "so_long");
	if (mlx.win == NULL)
		ft_close(game);
	ft_draw(game);
	mlx_expose_hook(mlx.win, ft_draw, game);
	mlx_hook(mlx.win, ClientMessage, NoEventMask, ft_close, game);
	mlx_key_hook(mlx.win, button_press, game);
	mlx_loop(mlx.mlx);
	return (0);
}
