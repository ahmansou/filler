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
	get_lims(&pc);
	ft_putstr_fd("x [", fd);
	ft_putnbr_fd(pc.xmin, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(pc.xmax, fd);
	ft_putstr_fd("], y [", fd);
	ft_putnbr_fd(pc.ymin, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(pc.ymax, fd);
	ft_putstr_fd("]", fd);
	attack(board, &pc, p, e, fd);
	exit(0);
	// free2d(pc.m);
	// free2d(board.m);
	// free2dint(board.hm);
	// ft_putstr_fd("12 14\n", 1);
	// ft_putstr_fd("8 2\n", 1);
	return(0);
}
