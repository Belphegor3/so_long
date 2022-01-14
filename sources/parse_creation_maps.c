/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_creation_maps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:47:58 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/14 15:08:49 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	count_nb_colrow(t_game *game, char *av)
{
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return (printf("\e[1,33mopen() failed\e[0m\n"), EXIT_FAILURE);
	game->line = get_next_line(game->fd);
	game->nb_col = ft_strlen(game->line, UNTIL_BACKSLASH_N);
	while (game->line)
	{						
		game->nb_row++;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	return (EXIT_SUCCESS);
}

int	create_1d_map(t_game *game, char *av)
{
	int	i;
	int	j;

	if (game->nb_col < 5 || game->nb_row < 3)
		return (printf("\e[1;5;31mHOW dare you\e[0m\n"), EXIT_FAILURE);
	game->ber = malloc(game->nb_col * game->nb_row + 1);
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return ((free(game->ber), printf("open() failed\n")), EXIT_FAILURE);
	game->line = get_next_line(game->fd);
	j = 0;
	while (game->line)
	{													
		i = 0;
		while (game->line && i < game->nb_col)
			game->ber[j++] = game->line[i++];
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	game->ber[j] = '\0';
	close(game->fd);
	return (EXIT_SUCCESS);
}

void	player_coordinates(t_game *game, int i, int j)
{
	while (game->line[++j] && j < game->nb_col)
	{
		if (game->line[j] == 'P')
		{
			game->player.col = j;
			game->player.row = i;
		}
		game->map[i][j] = game->line[j];
	}
	game->map[i++][j] = '\0';
	free(game->line);
	game->line = get_next_line(game->fd);
}

void	create_2d_map_norm(t_game *game, char *av)
{
	game->map = malloc(sizeof(char *) * (game->nb_row + 1));
	if (game->map == NULL)
		exit (0);
	game->map[game->nb_row] = NULL;
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
	{
		free(game->map);
		printf("\e[1;31mopen() failed\e[0m\n");
		exit (0);
	}
	game->line = get_next_line(game->fd);
}

int	create_2d_map(t_game *game, char *av, int i, int j)
{
	create_2d_map_norm(game, av);
	while (game->line)
	{
		game->len_loop = ft_strlen(game->line, UNTIL_BACKSLASH_N);
		if (game->len_loop != game->nb_col)
			return ((free(game->map), printf("Invalid map (not rect)\n")), 1);
		game->map[i] = malloc(sizeof(char) * game->nb_col + 1);
		if (game->map == NULL)
			return (EXIT_FAILURE);
		j = -1;
		while (game->line[++j] && j < game->nb_col)
		{
			if (game->line[j] == 'P')
			{
				game->player.col = j;
				game->player.row = i;
			}
			game->map[i][j] = game->line[j];
		}
		game->map[i++][j] = '\0';
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	return (EXIT_SUCCESS);
}
