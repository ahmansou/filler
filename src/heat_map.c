/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:25:42 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/24 14:25:50 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_full(int **hm, int h, int w)
{
	int x;
	int y;

	y = -1;
	while (++y < h && (x = -1))
		while (++x < w)
			if (hm[y][x] == 0)
				return (0);
	return (1);
}

static void	init_heatmap(t_board *br)
{
	int x;
	int y;

	br->hm = (int**)malloc(sizeof(int*) * (br->h));
	y = -1;
	while (++y < br->h && (x = -1))
	{
		br->hm[y] = (int*)malloc(sizeof(int) * (br->w));
		while (++x < br->w)
		{
			br->hm[y][x] = 0;
			if (br->m[y][x] == br->e || br->m[y][x] == br->e + 32)
				br->hm[y][x] = 1;
		}
	}
}

static void	fill_hm(t_board *br, int x, int y, int i)
{
	if (br->hm[y][x] == i && x + 1 < br->w && y + 1 < br->h &&
		br->hm[y + 1][x + 1] != i && br->hm[y + 1][x + 1] == 0)
		br->hm[y + 1][x + 1] = i + 1;
	if (br->hm[y][x] == i && x + 1 < br->w && y - 1 > 0 &&
		br->hm[y - 1][x + 1] != i && br->hm[y - 1][x + 1] == 0)
		br->hm[y - 1][x + 1] = i + 1;
	if (br->hm[y][x] == i && x - 1 >= 0 && y - 1 >= 0 &&
		br->hm[y - 1][x - 1] != i && br->hm[y - 1][x - 1] == 0)
		br->hm[y - 1][x - 1] = i + 1;
	if (br->hm[y][x] == i && x - 1 >= 0 && y + 1 < br->h &&
		br->hm[y + 1][x - 1] != i && br->hm[y + 1][x - 1] == 0)
		br->hm[y + 1][x - 1] = i + 1;
	if (br->hm[y][x] == i && x + 1 < br->w &&
		br->hm[y][x + 1] != i && br->hm[y][x + 1] == 0)
		br->hm[y][x + 1] = i + 1;
	if (br->hm[y][x] == i && x - 1 >= 0 &&
		br->hm[y][x - 1] != i && br->hm[y][x - 1] == 0)
		br->hm[y][x - 1] = i + 1;
	if (br->hm[y][x] == i && y + 1 < br->h &&
		br->hm[y + 1][x] != i && br->hm[y + 1][x] == 0)
		br->hm[y + 1][x] = i + 1;
	if (br->hm[y][x] == i && y - 1 >= 0 &&
		br->hm[y - 1][x] != i && br->hm[y - 1][x] == 0)
		br->hm[y - 1][x] = i + 1;
}

static void	clear_pos(t_board *br)
{
	int x;
	int y;

	y = -1;
	while (++y < br->h)
	{
		x = -1;
		while (++x < br->w)
			if (br->m[y][x] == br->p)
				br->hm[y][x] = 0;
	}
}

void		heatmap(t_board *br)
{
	int i;
	int x;
	int y;

	i = 1;
	init_heatmap(br);
	while (!is_full(br->hm, br->h, br->w) && (y = -1))
	{
		while (++y < br->h && (x = -1))
			while (++x < br->w)
				fill_hm(br, x, y, i);
		i++;
	}
	clear_pos(br);
}
