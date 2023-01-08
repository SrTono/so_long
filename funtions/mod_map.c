/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:01:39 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/12 13:00:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mod_map(int new_col, int new_fil, t_game *game)
{
	game->status = 0;
	if (game->map[new_col][new_fil] == '1')
		return (game->num_mob);
	else if (game->map[new_col][new_fil] == 'C')
	{
		game->num_c++;
		game->status = 1;
	}
	if (game->map[new_col][new_fil] == 'E')
	{
		if (game->tot_c != game->num_c)
		{
			game->status = 1;
			return (game->num_mob);
		}
		game->fin = 1;
	}
	game->col_back = game->col_jp;
	game->fil_back = game->fil_jp;
	game->num_mob++;
	game->map[game->col_jp][game->fil_jp] = '0';
	game->map[new_col][new_fil] = 'P';
	game->col_jp = new_col;
	game->fil_jp = new_fil;
	ft_status(game);
	return (game->num_mob);
}

void ft_status(t_game *game)
{
	ft_printf("Numero de Movimientos -> %d\n", game->num_mob);
	ft_printf("Numero de Colecionables -> %d/%d\n", game->num_c, game->tot_c);
	ft_printf("-------------------------------\n");
}
