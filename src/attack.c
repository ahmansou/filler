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

static int	it_touches(t_piece *pc, t_board br, int c[])
{
	int px;
	int py;
	int x;
	int y;

	y = c[0];
	py = pc->ymin;
	while (py <= pc->ymax && y < br.h)
	{
		px = pc->xmin;
		x = c[1];
		while (px <= pc->xmax && x < br.w)
		{
			if (pc->m[py][px] == '*' && br.m[y][x] == br.p)
				return (1);
			px++;
			x++;
		}
		py++;
		y++;
	}
	return (0);
}

static int	it_fits(t_piece pc, t_board br, int c[])
{
	int	px;
	int	py;
	int x;
	int y;

	y = c[0] - 1;
	if (pc.xmax < br.w && pc.xmin >= 0 && pc.ymax < br.h && pc.ymin >= 0)
	{
		py = pc.ymin - 1;
		while (++py + (++y * 0) <= pc.ymax && ++y < br.h)
		{
			px = pc.xmin - 1;
			x = c[1] - 1;
			while (++px + (++x * 0) <= pc.xmax)
				if (pc.m[py][px] == '*' && br.m[y][x] == br.e)
					return (0);
		}
		return (1);
	}
	return (0);
}

static void	init_score(t_score *score)
{
	score->score = 999999;
	score->x = 0;
	score->y = 0;
}

static int	cal_score(t_piece pc, t_board br, int c[])
{
	int bx;
	int by;
	int x;
	int y;
	int sc;

	sc = 0;
	y = pc.ymin - 1;
	by = c[0] - 1;
	while (++y + (++by * 0) <= pc.ymax)
	{
		x = pc.xmin - 1;
		bx = c[1] - 1;
		while (++x + (++bx * 0) <= pc.xmax)
			if(pc.m[y][x] == '*')
				sc += br.hm[by][bx];
	}
	return (sc);
}

void		attack(t_board br, t_piece *pc, int fd)
{
	int 	x;
	int 	y;
	int		coor[2];
	t_score	score;

	y = -1;
	init_score(&score);
	while (++y < br.h && (x = -1))
		while (++x < br.w)
		{
			coor[0] = y;
			coor[1] = x;
			if (it_fits(*pc, br, coor) && it_touches(pc, br, coor))
			{
				score.s = cal_score(*pc, br, coor);
				if (score.s < score.score)
				{
					score.x = x;
					score.y = y;
					score.score = score.s;
				}
				put_coor(y - pc->ymin, x - pc->xmin);
				return ;
			}
		}
}