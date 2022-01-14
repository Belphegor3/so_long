/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:41:04 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/14 17:22:00 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W)
		key_w(game);
	else if (keycode == KEY_A)
		key_a(game);
	else if (keycode == KEY_S)
		key_s(game);
	else if (keycode == KEY_D)
		key_d(game);
	else
		return (printf("Available keys are W,A,S,D,esc\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			TILE_SIZE * game->nb_col, TILE_SIZE * game->nb_row, "so_long");
}

int	game_close(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (check_is_it_ber(ac, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game = (t_game){0};
	count_nb_colrow(&game, av[1]);
	if (create_1d_map(&game, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_2d_map(&game, av[1], 0, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_errors(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	window_init(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &deal_key, &game);
	mlx_hook(game.win, DestroyNotify, LeaveWindowMask, &game_close, &game);
	refresh_map(&game, -1, 0, 0);
	mlx_loop(game.mlx);
}
