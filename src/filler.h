/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:26:15 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/24 14:26:18 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 1
# define FD_LIMIT 4864

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf.h"

typedef struct	s_board
{
	char	**m;
	int		**hm;
	int		w;
	int		h;
	char	p;
	char	e;
}				t_board;

typedef struct	s_piece
{
	char	**m;
	int		w;
	int		h;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
}				t_piece;

typedef struct s_score
{
	int x;
	int y;
	int score;
	int s;
}				t_score;

int		get_next_line(const int fd, char **line);
void	get_player(t_board *board);
void	get_assets(t_board *board, t_piece *pc);
void	heatmap(t_board *br);
void	get_lims(t_piece *pc);
void	put_coor(int x, int y);
// void	attack(t_board brd, t_piece pc, int fd);
void	attack(t_board brd, t_piece pc);

#endif

