/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:11:11 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/14 17:22:17 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_2d_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && i < game->nb_row)
	{	
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_1d_map(t_game *game)
{
	free(game->ber);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	while (game->map && i < game->nb_row)
		free(game->map[i++]);
	free(game->map);
}
