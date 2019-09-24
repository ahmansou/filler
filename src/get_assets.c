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
	int		i;

	tmp = line + 8;
	board->h = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	board->w = ft_atoi(tmp + 1);
	board->m = (char**)malloc(sizeof(char*) * (board->h + 1));
	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < board->h)
	{
		get_next_line(0, &line);
		board->m[i] =  ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	board->m[i] = 0;
}

static void	get_piece(t_piece	*pc, char *line)
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
		get_next_line(0, &line);
		pc->m[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	pc->m[i] = 0;
}

void		get_assets(t_board *board, t_piece *pc, t_player *p, t_player *e)
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
	heatmap(board, *e);
}
