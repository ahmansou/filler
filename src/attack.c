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

static int	it_touches(t_piece *pc, t_board br, t_player p, int c[])
{
	int xtmp;
	int y;
	int x;

	y = c[0];
	x = c[1];
	pc->ytouch = pc->ymin;
	while (pc->ytouch <= pc->ymax)
	{
		pc->xtouch = pc->xmin;
		xtmp = x;
		while (pc->xtouch <= pc->xmax)
		{
			if (pc->m[pc->ytouch][pc->xtouch] == '*' && br.m[y][xtmp] == p.l)
				return (1);
			pc->xtouch++;
			xtmp++;
		}
		pc->ytouch++;
		y++;
	}
	return (0);
}

static int	it_fits(t_piece pc, t_board br, t_player e, int c[])
{
	int xtmp;
	int	px;
	int	py;
	int y;
	int x;

	y = c[0];
	x = c[1];
	if (pc.xmax < br.w && pc.xmin >= 0 && pc.ymax < br.h && pc.ymin >= 0)
	{
		py = pc.ymin - 1;
		y--;
		while (++py + (++y * 0) <= pc.ymax)
		{
			px = pc.xmin - 1;
			xtmp = x - 1;
			while (++px + (++xtmp * 0) <= pc.xmax)
				if (pc.m[py][px] == '*' && br.m[y][xtmp] == e.l)
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
	int sc;
	int x;
	int y;
	int bx;
	int by;

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

void		attack(t_board br, t_piece *pc, t_player p, t_player e, int fd)
{
	int 	x;
	int 	y;
	int		coor[2];
	int		score;
	t_score	cscore;

	y = -1;
	init_score(&cscore);
	while (++y < br.h && (x = -1))
		while (++x < br.w)
		{
			coor[0] = y;
			coor[1] = x;
			if (it_fits(*pc, br, e, coor) && it_touches(pc, br, p, coor))
			{
				score = cal_score(*pc, br, coor);
				cscore.score = (score < cscore.score) ? score : cscore.score;
				cscore.x = (score < cscore.score) ? x : cscore.x;
				cscore.y = (score < cscore.score) ? y : cscore.y;
				ft_putendl_fd("", fd);
				ft_putstr_fd("[", fd);
				ft_putnbr_fd(y,fd);
				ft_putstr_fd(", ", fd);
				ft_putnbr_fd(x,fd);
				ft_putstr_fd("] ", fd);
				ft_putstr_fd("score = ", fd);
				ft_putnbr_fd(score,fd);
				ft_putendl_fd("", fd);
			}
		}
	print_coor(cscore.x - pc->xmin, cscore.y - pc->ymin);
}