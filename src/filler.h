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

# define BUFF_SIZE 11
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
}				t_board;

typedef struct s_score
{
	int x;
	int y;
	int score;
}				t_score;


typedef struct	s_piece
{
	char	**m;
	int		w;
	int		h;
	int		xtouch;
	int		ytouch;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
}				t_piece;

typedef struct	s_player
{
	char	l;
	int		ix;
	int		iy;
}				t_player;

typedef	struct	s_coor
{
	int	x;
	int y;
}				t_coor;

int		get_next_line(const int fd, char **line);
void	get_assets(t_board *board, t_piece *pc, t_player *p, t_player *e);
void	free2d(char **s);
void	free2dint(int **s);
void	heatmap(t_board *br, t_player e, t_player p);
void	get_lims(t_piece *pc);
void	attack(t_board br, t_piece *pc, t_player e, t_player p, int fd);
void	print_coor(int x, int y);

#endif

