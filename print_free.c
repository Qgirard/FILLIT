/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:12:59 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/12 15:46:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		delall(t_piece **stock, char **str, char **line)
{
	t_point *tmp_point;
	t_piece *tmp_piece;

	if (line)
		ft_strdel(line);
	ft_strdel(str);
	while ((*stock))
	{
		tmp_piece = (*stock);
		while ((*stock)->piece)
		{
			tmp_point = (*stock)->piece;
			tmp_point->x = 0;
			tmp_point->y = 0;
			free(tmp_point);
			(*stock)->piece = (*stock)->piece->next;
		}
		tmp_piece->piece_nb = 0;
		(*stock) = (*stock)->next;
		free(tmp_piece);
	}
	return (-1);
}

int		print_free(char ***squ, char **str, t_piece **stock)
{
	int		i;
	char	*line;

	i = 0;
	delall(stock, str, &line);
	while ((*squ)[i])
		ft_putendl((*squ)[i++]);
	i = 0;
	while ((*squ)[i])
		ft_strdel(&(*squ)[i++]);
	free((*squ));
	return (1);
}
