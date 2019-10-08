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

static void init_vals(t_board *brd, t_piece *pc)
{
	brd->m = NULL;
	brd->hm = NULL;
	pc->m = NULL;
}
static void	freeme(t_piece *pc, t_board *board)
{
	int i;

	i = 0;
	while (i <= pc->h)
		ft_strdel(&pc->m[i++]);
	pc->m = NULL;
	i = 0;
	while (i <= board->h)
		ft_strdel(&board->m[i++]);
	board->m = NULL;
	i = 0;
	free(board->hm);
}

int	main(void)
{
	t_board		board;
	t_piece		pc;

	get_player(&board);
	while (1)
	{
		// init_vals(&board, &pc);
		if (!get_assets(&board, &pc))
			break ;
		get_lims(&pc);
		heatmap(&board);
		attack(board, pc);
		freeme(&pc, &board);
	}
	return (0);
}
