#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib/libft/libft.h"
#include "lib/get_next_line.h"

typedef struct	s_board
{
	char	**m;
	int		width;
	int		height;
}				t_board;

// typedef struct	s_piece
// {
// 	char	**piece;
// 	int		width;
// 	int		height;
// }				t_piece;

typedef struct	s_player
{
	char	l;
	int		x;
	int		y;
}				t_player;


void	get_board(t_board *board, char *line)
{
	char	*tmp;
	int		i;

	tmp = line + 8;
	board->height = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	board->width = ft_atoi(tmp + 1);
	board->m = (char**)malloc(sizeof(char*) * (board->height + 1));
	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < board->height)
	{
		get_next_line(0, &line);
		board->m[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	board->m[i] = 0;
}

void	get_piece(t_board	*pc, char *line, int fd)
{
	char	*tmp;
	char	c;
	int		x;
	int		y;

	tmp = line + 6;
	pc->height = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	pc->width = ft_atoi(tmp + 1);
	pc->m = (char**)malloc(sizeof(char*) * (pc->height + 1));
	// while (i < pc->height)
	// {
	// 	get_next_line(0, &line);
	// 	pc->m[i] = ft_strdup(line);
	// 	ft_strdel(&line);
	// 	// pc->m[i] = ft_strnew(pc->width);
	// 	// ft_memset(pc->m[i], '.', pc->width);
	// 	i++;
	// }
	y = 0;
	x = 0;
	while (y < pc->height)
	{
		write(fd, &c, 1);
		read(0, &c, 1);
		if (x == pc->width)
		{
			y++;
			x = 0;
		}
		else
			x++;

		// pc->m[y][x] = c;
	}
	pc->m[y] = 0;
}

void	free2d(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int main()
{
	char		*line;
	t_board		board;
	t_board		pc;
	t_player	p;
	t_player	e;
	int			i;
	int			fd;

	fd = open("output", O_WRONLY);
	while (get_next_line(0, &line))
	{
		if(!ft_strncmp(line, "$$$", 3))
		{
			p.l = (line[10] == '1') ? 'O' : 'X';
			e.l = (line[10] == '2') ? 'O' : 'X';
		}
		if(!ft_strncmp(line, "Plateau", 7))
			get_board(&board, line);
		if(!ft_strncmp(line, "Piece", 5))
		{
			get_piece(&pc, line, fd);
			break ;
		}
		ft_strdel(&line);
	}
	i = 0;

	ft_putendl_fd("", fd);
	ft_putstr_fd("player : ", fd);
	ft_putchar_fd(p.l, fd);
	ft_putendl_fd("\nboard :", fd);
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
