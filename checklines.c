/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:36:04 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/21 13:13:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		countdiez(char *str)
{
	static int	i;
	int			diez_nb;

	diez_nb = 0;
	if (ft_strlen(str) == 16)
		i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			diez_nb++;
		i++;
	}
	return (diez_nb == 4 ? 0 : -1);
}

static int		validtetri(char *line, t_piece **current_piece, int line_nb,
		t_piece **stock)
{
	int i;

	i = 0;
	if (ft_strlen(line) != 4 && line[4] != '\0')
		return (-1);
	if (line_nb == 1)
	{
		if (!(*current_piece = new_add_piece(stock)))
			return (-1);
	}
	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		if (line[i] == '#')
		{
			if (get_index(current_piece, line_nb, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int		tetrimino(char *line, char **str)
{
	static int piece_nb;

	if (ft_strlen(*str) == 16)
		piece_nb = 1;
	if (line[0] != '\0' || countdiez(*str) == -1)
		return (-1);
	piece_nb++;
	if (piece_nb > 26)
		return (-1);
	return (0);
}

static int		checklf(char *line, char **str)
{
	static int	gnl_ret;

	if (ft_strlen(*str) == 4)
		gnl_ret = 0;
	if (line)
	{
		if (line[0] == '\0')
			gnl_ret++;
	}
	return (gnl_ret);
}

int				checklines(t_piece **stock, const int fd, char **str)
{
	int		line_nb;
	char	*line;
	t_piece	*current_piece;

	line_nb = 0;
	current_piece = *stock;
	(*str) = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		(*str) = ft_strjoinf((*str), line, 1);
		checklf(line, str);
		if (++line_nb % 5 == 0)
		{
			if (tetrimino(line, str) == -1)
				return (delall(stock, str, &line));
			line_nb = 0;
		}
		else if (validtetri(line, &current_piece, line_nb, stock) == -1)
			return (delall(stock, str, &line));
		ft_strdel(&line);
	}
	if (((*str)[0] == '\0') || (checklf(line, str) != current_piece->piece_nb -
	1) || (tetricheck((*str)) == -1) || (countdiez(*str) == -1 || line_nb != 4))
		return (delall(stock, str, &line));
	return (0);
}
