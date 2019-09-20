#include "filler.h"

static void	get_board(t_board *board, char *line)
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
		board->m[i] =  ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	board->m[i] = 0;
}

static void	get_piece(t_board	*pc, char *line)
{
	char	*tmp;
	int		i;

	tmp = line + 6;
	pc->height = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	pc->width = ft_atoi(tmp + 1);
	pc->m = (char**)malloc(sizeof(char*) * (pc->height + 1));
	i = 0;
	while (i < pc->height)
	{
		get_next_line(0, &line);
		pc->m[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	pc->m[i] = 0;
}

void		get_assets(t_board *board, t_board *pc, t_player *p, t_player *e)
{
	char		*line;
	
	while (get_next_line(0, &line))
	{
		if(!ft_strncmp(line, "$$$", 3))
		{
			p->l = (line[10] == '1') ? 'O' : 'X';
			e->l = (line[10] == '2') ? 'O' : 'X';
		}
		if(!ft_strncmp(line, "Plateau", 7))
			get_board(board, line);
		if(!ft_strncmp(line, "Piece", 5))
		{
			get_piece(pc, line);
			break ;
		}
		ft_strdel(&line);
	}
}