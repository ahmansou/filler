
#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 11
# define FD_LIMIT 4864

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_board
{
	char	**m;
	int		**hm;
	int		w;
	int		h;
}				t_board;


typedef struct	s_piece
{
	char	**m;
	int		w;
	int		h;
	int		rl_wd;
	int		rl_hi;
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
void	heatmap(t_board *br);

#endif

