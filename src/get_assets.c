/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:25:20 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/24 14:25:24 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_board(t_board *board, char *line)
{
	char	*tmp;
	char 	*l;
	int		i;

	l = ft_strdup(line);
	tmp = l + 8;
	// free(line);
	board->h = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	board->w = ft_atoi(tmp + 1);
	board->m = (char**)malloc(sizeof(char*) * (board->h + 1));
	i = 0;
	if (get_next_line(0, &l) != 1)
		return ;
	ft_strdel(&l);
	while (i < board->h)
	{
		if (get_next_line(0, &l) != 1)
			return ;
		board->m[i] = ft_strdup(l + 4);
		ft_strdel(&l);
		i++;
	}
	board->m[i] = 0;
}

static void	get_piece(t_piece *pc, char *line)
{
	char	*tmp;
	int		i;

	tmp = line + 6;
	pc->h = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	pc->w = ft_atoi(tmp + 1);
	pc->m = (char**)malloc(sizeof(char*) * (pc->h + 1));
	i = 0;
	while (i < pc->h)
	{
		if (get_next_line(0, &line) != 1)
			return ;
		pc->m[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	pc->m[i] = 0;
}

void		get_player(t_board *board)
{
	char	*line;

	get_next_line(0, &line);
	board->p = (line[10] == '1') ? 'O' : 'X';
	board->e = (line[10] == '2') ? 'O' : 'X';
	ft_strdel(&line);
}

int		get_assets(t_board *board, t_piece *pc)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "Plateau", 7))
		{
			get_board(board, line);
			ft_strdel(&line);
		}
		else if (!ft_strncmp(line, "Piece", 5))
		{
			get_piece(pc, line);
			ft_strdel(&line);
			return (1) ;
		}
		else
		{
			ft_strdel(&line);
			return (0);
		}
	}
	return (0);
}
