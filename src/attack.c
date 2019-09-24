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

static int	it_touchs(t_piece *pc)
{
	pc->ytouch = pc->ymin;
	while (pc->ytouch < pc->ymax)
	{
		pc->xtouch = pc->xmin;
		while (pc->xtouch < pc->xmax)
		{
			if (pc->m[pc->ytouch][pc->xtouch] == '*')
				return (1);
			pc->xtouch++;
		}
		pc->ytouch++;
	}
	return (0);
}

static int	it_fits(t_piece pc, t_board br, int x, int y)
{
	if (pc.xmax >= br.w || pc.xmin < 0 || pc.ymax >= br.h || pc.ymin < 0)
		return (0);
	return (1);
}

void			attack(t_board br, t_piece *pc, t_player p, t_player e, int fd)
{
	t_score *score;
	int x;
	int y;

	// init_scores(score);
	y = 0;
	while (y < br.h)
	{
		x = 0;
		while (x < br.w)
		{
			if (br.m[y][x] == p.l && it_touchs(pc))
			// if (br.m[y][x] == p.l)
			{
				ft_putstr_fd("\n[", fd);
				ft_putnbr_fd(x - pc->xmin, fd);
				ft_putstr_fd(", ", fd);
				ft_putnbr_fd(y - pc->ymin, fd);
				ft_putendl_fd("]", fd);
				ft_putnbr_fd(y - pc->ymin, 1);
				ft_putstr_fd(" ", 1);
				ft_putnbr_fd(x - pc->xmin, 1);
				ft_putstr_fd("\n", 1);
				return ;
			}
			else if (br.m[y][x] == p.l && !it_touchs(pc))
			{
				ft_putstr_fd("0 0\n", 1);
			}
			
			x++;
		}
		y++;
	}
}