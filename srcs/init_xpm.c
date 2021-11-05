/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:29:05 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/05 17:29:08 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_xpm_player(t_mlx *mlx)
{
	mlx->xpm_plb = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/plb.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_plb)
		return (ft_error_dealer("Could not open plb.xpm file\n"));
	mlx->xpm_plw = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/plw.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_plw)
		return (ft_error_dealer("Could not open plw.xpm file\n"));
	mlx->xpm_prw = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/prw.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_prw)
		return (ft_error_dealer("Could not open prw.xpm file\n"));
	mlx->xpm_prb = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/prb.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_prb)
		return (ft_error_dealer("Could not open prb.xpm file\n"));
	return (0);
}

int	ft_init_xpm(t_mlx *mlx)
{
	mlx->xpm_black = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/black.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_black)
		return (ft_error_dealer("Could not open .xpm file\n"));
	mlx->xpm_white = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/white.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_white)
		return (ft_error_dealer("Could not open .xpm file\n"));
	mlx->xpm_wall = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/brown.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_wall)
		return (ft_error_dealer("Could not open .xpm file\n"));
	mlx->xpm_fw = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/food_white.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_fw)
		return (ft_error_dealer("Could not open .xpm file\n"));
	mlx->xpm_fb = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/food_black.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_fb)
		return (ft_error_dealer("Could not open food_black.xpm file\n"));
	if (ft_init_xpm_player(mlx) == 1)
		return (1);
	return (ft_init_xpm_1(mlx));
}

int	ft_init_xpm_1(t_mlx *mlx)
{
	mlx->xpm_ennemy_black = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/ennemy_black.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_ennemy_black)
		return (ft_error_dealer("Could not open ennemy_black.xpm file\n"));
	mlx->xpm_ennemy_white = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/ennemy_white.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_ennemy_white)
		return (ft_error_dealer("Could not open ennemy_white.xpm file\n"));
	mlx->xpm_exit_black = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/exit_black.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_exit_black)
		return (ft_error_dealer("Could not open exit_black.xpm file\n"));
	mlx->xpm_exit_white = mlx_xpm_file_to_image(mlx->mlx,
			"./xpm/exit_white.xpm", &mlx->width, &mlx->height);
	if (!mlx->xpm_exit_white)
		return (ft_error_dealer("Could not open exit_white.xpm file\n"));
	return (0);
}

void	ft_null_xpm(t_mlx *mlx)
{
	mlx->xpm_plb = NULL;
	mlx->xpm_plw = NULL;
	mlx->xpm_prb = NULL;
	mlx->xpm_prw = NULL;
	mlx->xpm_black = NULL;
	mlx->xpm_white = NULL;
	mlx->xpm_wall = NULL;
	mlx->xpm_fw = NULL;
	mlx->xpm_fb = NULL;
	mlx->xpm_exit_black = NULL;
	mlx->xpm_exit_white = NULL;
	mlx->xpm_ennemy_black = NULL;
	mlx->xpm_ennemy_white = NULL;
}
