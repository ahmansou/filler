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

void		heatmap(t_board *br)
{
	int i;
	int x;
	int y;

	i = 1;
	while (!is_full(br->hm, br->h, br->w) && (y = -1))
	{
		// if (is_full(br->hm, br->h, br->w))
		// 	break ;
		// y = 0;
		while (++y < br->h && (x = -1))
		{
			// x = 0;
			while (++x < br->w)
			{
				if (br->hm[y][x] == i && x + 1 < br->w && y + 1 < br->h && br->hm[y + 1][x + 1] != i && br->hm[y + 1][x + 1] == 0)
					br->hm[y + 1][x + 1] = i + 1;
				if (br->hm[y][x] == i && x + 1 < br->w && y - 1 > 0 && br->hm[y - 1][x + 1] != i && br->hm[y - 1][x + 1] == 0)
					br->hm[y - 1][x + 1] = i + 1;
				if (br->hm[y][x] == i && x - 1 >= 0 && y - 1 >= 0 && br->hm[y - 1][x - 1] != i && br->hm[y - 1][x - 1] == 0)
					br->hm[y - 1][x - 1] = i + 1;
				if (br->hm[y][x] == i && x - 1 >= 0 && y + 1 < br->h && br->hm[y + 1][x - 1] != i && br->hm[y + 1][x - 1] == 0)
					br->hm[y + 1][x - 1] = i + 1;
				if (br->hm[y][x] == i && x + 1 < br->w && br->hm[y][x + 1] != i && br->hm[y][x + 1] == 0)
					br->hm[y][x + 1] = i + 1;
				if (br->hm[y][x] == i && x - 1 >= 0 && br->hm[y][x - 1] != i && br->hm[y][x - 1] == 0)
					br->hm[y][x - 1] = i + 1;
				if (br->hm[y][x] == i && y + 1 < br->h && br->hm[y + 1][x] != i && br->hm[y + 1][x] == 0)
					br->hm[y + 1][x] = i + 1;
				if (br->hm[y][x] == i && y - 1 >= 0 && br->hm[y - 1][x] != i && br->hm[y - 1][x] == 0)
					br->hm[y - 1][x] = i + 1;
				// x++;
			}
			// y++;
		}	
		i++;
	}
}