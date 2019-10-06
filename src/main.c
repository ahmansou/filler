/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:25:31 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/24 14:25:33 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void freeboard(t_board *brd)
{
	int i;

	i = 0;
	while (i < brd->h)
		free(brd->m[i++]);
	free(brd->m);
	brd->m = NULL;
}

int main()
{
	t_board		board;
	t_piece		pc;

	get_player(&board);
	board.m = NULL;
	while (1)
	{
		get_assets(&board, &pc);
		get_lims(&pc);
		heatmap(&board);
		attack(board, pc);
		freeboard(&board);
	}
	return(0);
}
