/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:39:11 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/23 15:39:13 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_pc(t_piece *pc)
{
	pc->xmax = 0;
	pc->xmin = 100;
	pc->ymax = 0;
	pc->ymin = 100;
	pc->xtouch = 0;
	pc->ytouch = 0;
}

void	get_lims(t_piece *pc)
{
	int x; 
	int y;

	init_pc(pc);
	y = -1;
	while (++y < pc->h && (x = -1))
		while (++x < pc->w)
			if (pc->m[y][x] == '*')
			{
				pc->ymax = (y > pc->ymax) ? y : pc->ymax;
				pc->xmax = (x > pc->xmax) ? x : pc->xmax;
			}
	y = pc->h;
	while (--y >= 0 && (x =pc->w))
		while (--x >= 0)
			if (pc->m[y][x] == '*')
			{
				pc->ymin = (y < pc->ymin) ? y : pc->ymin;
				pc->xmin = (x < pc->xmin) ? x : pc->xmin;
			}
}