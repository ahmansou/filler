/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 09:26:52 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/23 09:26:55 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_scores(t_score *score)
{
	score->score = 300;
	score->x = 0;
	score->y = 0;
}

static void	it_fits(t_piece pc, char **brd, t_score score)
{
	int x;
	int y;

	y = 0;
}

int			attack(t_board br, t_piece pc, t_player e, t_player p)
{
	t_score score;
	int x;
	int y;
	int px;
	int py;
	int score;

	init_scores(&score);
	y = 0;
	while (y < br.h)
	{
		x = 0;
		while (x < br.w)
		{
			
			x++;
		}
		y++;
	}
	return (0);
}