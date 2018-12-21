/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:07:59 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/12 18:10:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		posealpha(t_piece **stock, char ***squ, int i, int j)
{
	char	c;
	t_point *current_piece;

	c = (*stock)->piece_nb + 64;
	current_piece = (*stock)->piece;
	(*squ)[i][j] = c;
	(*squ)[i + current_piece->next->y][j + current_piece->next->x] = c;
	(*squ)[i + current_piece->next->next->y]
	[j + current_piece->next->next->x] = c;
	(*squ)[i + current_piece->next->next->next->y]
	[j + current_piece->next->next->next->x] = c;
	return (0);
}

static int		checkpos(int x, int y, int pos, char **squ)
{
	int			i;
	int			j;
	int			len;

	len = ft_strlen(squ[0]);
	i = pos / len;
	j = pos % len;
	if (((i + y) >= 0) && (i + y < len) && ((j + x) >= 0) && (j + x < len) &&
			squ[i + y][j + x] == '.')
		return (1);
	else
		return (0);
}

static int		posepiece(t_piece **stock, int x, char ***squ, int pos)
{
	t_point	*current_diez;
	int		i;
	int		j;

	i = pos / x;
	j = pos % x;
	current_diez = (*stock)->piece;
	if ((*squ)[i][j] != '.')
		return (-1);
	if ((checkpos(current_diez->next->x, current_diez->next->y, pos,
		(*squ)) == 1) && (checkpos(current_diez->next->next->x,
		current_diez->next->next->y, pos, (*squ)) == 1) &&
		(checkpos(current_diez->next->next->next->x,
		current_diez->next->next->next->y, pos, (*squ)) == 1))
		posealpha(stock, squ, i, j);
	else
		return (-1);
	return (0);
}

static void		delpiece(char ***squ, int piece_nb)
{
	int		i;
	int		j;

	i = 0;
	while ((*squ)[i])
	{
		j = 0;
		while ((*squ)[i][j])
		{
			if ((*squ)[i][j] == piece_nb + 64)
				(*squ)[i][j] = '.';
			j++;
		}
		i++;
	}
}

int				trypiece(int x, char ***squ, int pos, t_piece *stock)
{
	t_piece *current_piece;

	current_piece = stock;
	while (current_piece)
	{
		if (posepiece(&current_piece, x, squ, pos) == 0)
		{
			if (trypiece(x, squ, 0, current_piece->next))
				return (1);
			delpiece(squ, current_piece->piece_nb);
			pos++;
		}
		else
		{
			if (pos == x * x - 1)
				return (0);
			pos++;
		}
	}
	return (1);
}
