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

// static void	freeme(t_piece *pc, t_board *board)
// {
// 	int i;

// 	i = 0;
// 	while (i <= pc->h)
// 		ft_strdel(&pc->m[i++]);
// 	free(pc->m);
// 	i = 0;
// 	while (i <= board->h)
// 		ft_strdel(&board->m[i++]);
// 	free(board->m);
// 	free(board->hm);
// }

static void	free2d(char **s)
{
	int x;

	x = 0;
	while (s[x])
		free(s[x++]);
	free(s);
	s = NULL;
}

static void	free2dint(int **s)
{
	int x;

	x = 0;
	// while (s[x])
	// 	free(s[x++]);
	free(s);
	// s = NULL;
}

int	main(void)
{
	t_board		board;
	t_piece		pc;

	get_player(&board);
	while (1)
	{
		if (!get_assets(&board, &pc))
			break ;
		get_lims(&pc);
		heatmap(&board);
		attack(board, pc);
		free2d(pc.m);
		free2d(board.m);
		free2dint(board.hm);
	}
	return (0);
}
