#include "filler.h"

int main()
{
	t_board		board;
	t_piece		pc;
	t_player	p;
	t_player	e;
	int			i;
	int 		j;
	int			fd;

	fd = open("output", O_WRONLY);

	get_assets(&board, &pc, &p, &e);

	ft_putstr_fd("2 8\n", 1);

	ft_putendl_fd("", fd);
	ft_putstr_fd("player : ", fd);
	ft_putchar_fd(p.l, fd);
	ft_putendl_fd("\nboard :", fd);
	i = 0;
	while (i < board.h)
		ft_putendl_fd(board.m[i++], fd);
	ft_putendl_fd("", fd);
	ft_putendl_fd("\nheat map :", fd);
	i = 0;
	while (i < board.h)
	{
		j = 0;
		while (j < board.w)
		{
			if (board.hm[i][j] < 100)
			{
				ft_putstr_fd(" ", fd);
				if (board.hm[i][j] < 10)
					ft_putstr_fd(" ", fd);
			}
			ft_putnbr_fd(board.hm[i][j], fd);
			ft_putstr_fd(" ", fd);
			j++;
		}
		ft_putendl_fd("", fd);
		// ft_putendl_fd("", fd);
		i++;
	}
	ft_putendl_fd("", fd);
	i = 0;
	ft_putendl_fd("piece :", fd);
	while (i < pc.h)
		ft_putendl_fd(pc.m[i++], fd);
	free2d(pc.m);
	free2d(board.m);
	return(0);
}
