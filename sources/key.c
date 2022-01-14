/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:58:09 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/14 17:24:20 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	key_a(t_game *game)
{
	int	result_move;

	result_move = move_left(game);
	if (result_move == EXIT_FAILURE)
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		free_all(game);
		exit(0);
	}
	else if (result_move == EXIT_NOTHING)
		;
	else
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		game->player.col = game->player.col - 1;
	}
}

void	key_d(t_game *game)
{
	int	result_move;

	result_move = move_right(game);
	if (result_move == EXIT_FAILURE)
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		free_all(game);
		exit(0);
	}
	else if (result_move == EXIT_NOTHING)
		;
	else
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		game->player.col = game->player.col + 1;
	}
}

void	key_w(t_game *game)
{
	int	result_move;

	result_move = move_up(game);
	if (result_move == EXIT_FAILURE)
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		free_all(game);
		exit(0);
	}
	else if (result_move == EXIT_NOTHING)
		;
	else
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		game->player.row = game->player.row - 1;
	}
}

void	key_s(t_game *game)
{
	int	result_move;

	result_move = move_down(game);
	if (result_move == EXIT_FAILURE)
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		free_all(game);
		exit(0);
	}
	else if (result_move == EXIT_NOTHING)
		;
	else
	{
		game->move_count++;
		printf("movement count : %d\n", game->move_count);
		refresh_map(game, -1, 0, 0);
		game->player.row = game->player.row + 1;
	}
}
