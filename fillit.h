/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:36:15 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 12:03:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef	struct	s_point
{
	int					x;
	int					y;
	struct s_point		*next;
}				t_point;

typedef struct	s_piece
{
	int					piece_nb;
	t_point				*piece;
	struct s_piece		*next;
}				t_piece;

int				checklines(t_piece **stock, const int fd, char **str);
int				get_index(t_piece **current_piece, int line_nb, int i);
t_piece			*new_add_piece(t_piece **stock);
int				tetricheck(char *str);
int				trypiece(int x, char ***squ, int pos, t_piece *stock);
int				delall(t_piece **stock, char **str, char **line);
int				print_free(char ***squ, char **str, t_piece **stock);

#endif
