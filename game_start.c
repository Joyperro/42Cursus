/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:39:25 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 13:02:31 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game);
t_tile	**map_init(int argc, char **argv, t_game *game);

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!is_valid_file(argc, argv))
		return (NULL);
	map = map_reader(argv[1]);
	if (!map)
		return (NULL);
	if (!is_valid_map(map))
	{
		free_map(map);
		return (NULL);
	}
	tilemap = tilemap_generator(map, game);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
}

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->win_size.x + TILE_SIZE / 2, game->win_size.y,
			"so_long");
	mlx_hook(game->win_ptr, 17, 0, end_program, game);
	anim_setup(game);
	open_img(game);
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->ac_collectables = 0;
	game->num_moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collectables = game->ac_collectables;
	game_init(game);
	return (TRUE);
}
