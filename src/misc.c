/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:26:05 by ahmansou          #+#    #+#             */
/*   Updated: 2019/09/24 14:26:07 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free2d(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	free2dint(int **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	print_coor(int x, int y)
{
	ft_putnbr_fd(y, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(x, 1);
	ft_putstr_fd("\n", 1);
}