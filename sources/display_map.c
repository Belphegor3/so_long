/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 05:46:44 by lfchouch          #+#    #+#             */
/*   Updated: 2022/01/14 15:03:29 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*xpm_file(t_game *game, char *index)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx, index,
			&game->img_struct.width, &game->img_struct.height);
	if (!image)
	{
		printf("valid xpm files needed\n");
		exit(0);
	}
	return (image);
}

int	refresh_map(t_game *game, int i, int j, int index)
{
	const char	key[] = "10CEP";
	const char	*val[] = {WALL, ZERO, COLLECT, EXIT, PLAYER, NULL};

	if (game->win == NULL)
		return (EXIT_FAILURE);
	while (game->map[++i] && i < game->nb_row)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n' && j < game->nb_col)
		{
			index = -1;
			while (key[++index])
			{
				if (game->map[i][j] == key[index])
				{
					game->img_struct.img = xpm_file(game, (char *)val[index]);
					break ;
				}
			}
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_struct.img, (j++) * TILE_SIZE, i * TILE_SIZE);
			mlx_destroy_image(game->mlx, game->img_struct.img);
		}
	}
	return (EXIT_SUCCESS);
}
