/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 03:29:30 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/13 06:53:49 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count_collectibles;

	i = 0;
	count_collectibles = 0;
	while (game->map && i < game->nb_row)
	{
		j = 0;
		while (game->map[i][j] && j <= game->nb_col)
			if (game->map[i][j++] == 'C')
				count_collectibles++;
		i++;
	}
	return (count_collectibles);
}

int	move_left(t_game *game)
{	
	if (game->map[game->player.row][game->player.col - 1] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row][game->player.col - 1] == 'C')
		return ((game->map[game->player.row][game->player.col] = '0',
			game->map[game->player.row][game->player.col - 1] = 'P'),
			EXIT_SUCCESS);
	if (game->map[game->player.row][game->player.col - 1] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row][game->player.col - 1] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row][game->player.col - 1] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col - 1] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

int	move_right(t_game *game)
{
	if (game->map[game->player.row][game->player.col + 1] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row][game->player.col + 1] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col + 1] = 'P', 0);
	}
	if (game->map[game->player.row][game->player.col + 1] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row][game->player.col + 1] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row][game->player.col + 1] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col + 1] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

int	move_up(t_game *game)
{
	if (game->map[game->player.row - 1][game->player.col] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row - 1][game->player.col] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row - 1][game->player.col] = 'P', 0);
	}
	if (game->map[game->player.row - 1][game->player.col] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row - 1][game->player.col] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row - 1][game->player.col] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row - 1][game->player.col] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

int	move_down(t_game *game)
{
	if (game->map[game->player.row + 1][game->player.col] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row + 1][game->player.col] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row + 1][game->player.col] = 'P', 0);
	}
	if (game->map[game->player.row + 1][game->player.col] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row + 1][game->player.col] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row + 1][game->player.col] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row + 1][game->player.col] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}
