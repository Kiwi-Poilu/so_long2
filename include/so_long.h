/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:38:40 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/05 18:38:43 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"
# include "get_next_line.h"

typedef struct s_map{
	char	**map;
	int		width;
	int		height;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*xpm_black;
	void	*xpm_white;
	void	*xpm_wall;
	void	*xpm_fb;
	void	*xpm_fw;
	void	*xpm_plb;
	void	*xpm_prb;
	void	*xpm_plw;
	void	*xpm_prw;
	void	*xpm_exit_black;
	void	*xpm_exit_white;
	void	*xpm_ennemy_black;
	void	*xpm_ennemy_white;
	int		height;
	int		width;
}				t_mlx;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	char	direction;
	int		move;
	char	*str_move;
}				t_game;

//display.c
void	display_player(t_game *game, int i, int j);
void	display_food(t_game *game, int i, int j);
void	display_ennemy(t_game *game, int i, int j);
void	display_exit(t_game *game, int i, int j);

//main.c
int		gnl_proxy(int fd, char **line);
char	**ft_store_map(int fd);
int		ft_check_ber(char *str);
int		ft_free_map(t_game *game);
int		main(int ac, char **av);

//ft_itoa.c
int		to_malloc(long n);
char	*ft_itoa(int n);

//check_walls.c
int		check_full_row(char *line);
int		check_walls(char *line);
int		check_all_walls(t_game *game);

//keys.c
int		button_press(int keycode, t_game *game);
int		wads_pressed(t_game *game, int keycode);

//game.c
int		ft_check_food(t_game *game);
void	ft_tile(t_game *game, char c, int i, int j);
void	ft_draw(t_game	*game);
void	move_player(t_game *game);
int		ft_game(t_map *map, t_game *game);

//init_xpm.c
int		ft_init_xpm_1(t_mlx *mlx);
int		ft_init_xpm(t_mlx *mlx);
int		ft_init_xpm_player(t_mlx *mlx);
void	ft_null_xpm(t_mlx *mlx);

//mlx_setup.c
int		ft_fill_struct(t_game *game, t_map *map, t_mlx *mlx);
int		ft_close(t_game *game);
void	ft_destroy_image(void *mlx, void *xpm);

//pce.c
int		ft_val_pce(int pce[3]);
void	check_pce_line(int i, t_game *game, int pce[3]);
int		check_pce(t_game *game);

//parsing.c
int		ft_error_dealer(char *error);
int		ft_map_height(char **map);
int		set_width_height(t_game *game);
int		parsing(t_game *game);
int		check_ber(char *str);
//ft_putchar.c
void	ft_putchar(char c);

//ft_putstr.c
void	ft_putstr(char *str);

//ft_split.c
char	**ft_split(char const *s, char c);

#endif
