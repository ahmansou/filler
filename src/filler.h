
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
	int		width;
	int		height;
}				t_board;

typedef struct	s_player
{
	char	l;
	int		x;
	int		y;
}				t_player;

typedef	struct	s_coor
{
	int	x;
	int y;
}				t_coor;

int		get_next_line(const int fd, char **line);
void	get_assets(t_board *board, t_board *pc, t_player *p, t_player *e);
void	free2d(char **s);

#endif

