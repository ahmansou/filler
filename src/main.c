#include "filler.h"

int main()
{
	t_board		board;
	t_board		pc;
	t_player	p;
	t_player	e;
	int			i;
	int			fd;

	fd = open("output", O_WRONLY);

	get_assets(&board, &pc, &p, &e);

	ft_putstr_fd("2 8\n", 1);

	ft_putendl_fd("", fd);
	ft_putstr_fd("player : ", fd);
	ft_putchar_fd(p.l, fd);
	ft_putendl_fd("\nboard :", fd);
	i = 0;
	while (i < board.height)
		ft_putendl_fd(board.m[i++], fd);
	i = 0;
	ft_putendl_fd("piece :", fd);
	while (i < pc.height)
		ft_putendl_fd(pc.m[i++], fd);
	free2d(pc.m);
	free2d(board.m);
	return(0);
}
