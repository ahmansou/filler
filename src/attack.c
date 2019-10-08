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

static int	it_fits(t_piece pc, t_board brd, int x, int y)
{
	if (pc.ymin < 0 || pc.xmin < 0 ||
		y + pc.ymax >= brd.h || x + pc.xmax >= brd.w)
		return (0);
	return (1);
}

static int	it_puts(t_piece pc, t_board brd, int x, int y)
{
	int px;
	int py;
	int bx;

	py = pc.ymin;
	while (py <= pc.ymax && y < brd.h)
	{
		bx = x;
		px = pc.xmin;
		while (px <= pc.xmax && bx < brd.w)
		{
			if (pc.m[py][px] == '*' &&
				(brd.m[y][bx] == brd.e || brd.m[y][bx] == brd.e + 32))
				return (0);
			px++;
			bx++;
		}
		py++;
		y++;
	}
	return (1);
}

static int	it_touchs(t_piece pc, t_board brd, int x, int y)
{
	int px;
	int py;
	int bx;
	int touches;

	py = pc.ymin;
	touches = 0;
	while (py <= pc.ymax && y < brd.h)
	{
		bx = x;
		px = pc.xmin;
		while (px <= pc.xmax && bx < brd.w)
		{
			if (pc.m[py][px] == '*' &&
				(brd.m[y][bx] == brd.p || brd.m[y][bx] == brd.p + 32))
				touches++;
			px++;
			bx++;
		}
		y++;
		py++;
	}
	return (touches);
}

static int	calculate(t_piece pc, t_board brd, int x, int y)
{
	int px;
	int py;
	int bx;
	int score;

	py = pc.ymin;
	score = 0;
	while (py <= pc.ymax && y < brd.h)
	{
		bx = x;
		px = pc.xmin;
		while (px <= pc.xmax && bx < brd.w)
		{
			if (pc.m[py][px] == '*')
				score += brd.hm[y][bx];
			px++;
			bx++;
		}
		py++;
		y++;
	}
	return (score);
}

void		attack(t_board brd, t_piece pc)
{
	t_score	score;
	int		x;
	int		y;
	int		cscore;

	score.score = 900000;
	score.x = 0;
	score.y = 0;
	y = -1;
	while (++y < brd.h && (x = -1))
		while (++x < brd.w)
			if (it_fits(pc, brd, x, y) && it_puts(pc, brd, x, y) &&
				it_touchs(pc, brd, x, y) == 1)
			{
				cscore = calculate(pc, brd, x, y);
				if (cscore < score.score)
				{
					score.score = cscore;
					score.x = x;
					score.y = y;
				}
			}
	ft_printf("%d %d\n", score.y - pc.ymin, score.x - pc.xmin);
}
