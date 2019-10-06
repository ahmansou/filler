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
	// int			fd;
	// int	i;
	// int	j;
	
	// fd = open("output", O_WRONLY);
	get_player(&board);
	// ft_putstr_fd("Me ", fd);
	// ft_putchar_fd(board.p, fd);
	// ft_putendl_fd("", fd);
	while (1)
	{
		get_assets(&board, &pc);
		get_lims(&pc);
		heatmap(&board);
		attack(board, pc);
		// attack(board, pc, fd);
		//DEBUGING:
		// i = 0;
		// while (i < board.h)
		// 	ft_putendl_fd(board.m[i++], fd);
		// ft_putendl_fd("", fd);
		// i = -1;
		// while (++i < board.h && (j = -1))
		// {
		// 	while (++j < board.w)
		// 	{
		// 		if (board.hm[i][j] < 10)
		// 			ft_putstr_fd(" ", fd);
		// 		ft_putstr_fd(" ", fd);
		// 		ft_putnbr_fd(board.hm[i][j], fd);
		// 	}
		// 	ft_putendl_fd("", fd);
		// }
		// ft_putendl_fd("", fd);
		// i = 0;
		// while (i < pc.h)
		// 	ft_putendl_fd(pc.m[i++], fd);
		// ft_putendl_fd("", fd);
		// ft_putstr_fd("xmin ", fd);
		// ft_putnbr_fd(pc.xmin, fd);
		// ft_putstr_fd(" xmax ", fd);
		// ft_putnbr_fd(pc.xmax, fd);
		// ft_putstr_fd(" ymin ", fd);
		// ft_putnbr_fd(pc.ymin, fd);
		// ft_putstr_fd(" ymax ", fd);
		// ft_putnbr_fd(pc.ymax, fd);
		
		// ft_putstr("12 14\n");
		// exit(0);
		// return(0);
	}
	// exit(0);
	return(0);
}
