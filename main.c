/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:37:33 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 15:52:03 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		putosquareroot(t_piece **stock)
{
	int		i;
	int		a;
	t_piece	*current_piece;

	current_piece = *stock;
	while (current_piece->next)
		current_piece = current_piece->next;
	a = current_piece->piece_nb * 4;
	i = 1;
	if (a <= 0)
		return (0);
	if (a == 1)
		return (1);
	while (a)
	{
		i = 1;
		while (i * i < a)
			i++;
		if (i * i == a && a / i == i && a % i == 0)
			return (i);
		a--;
	}
	return (0);
}

static int		putpoints(char ***squ, int i, int x)
{
	int j;

	i = 0;
	while (i < x)
	{
		if (!((*squ)[i++] = (char*)ft_memalloc(sizeof(char) * x + 1)))
			return (-1);
	}
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < x)
			(*squ)[i][j++] = '.';
		i++;
	}
	return (0);
}

static int		put_tab(int x, t_piece **stock, char ***squ)
{
	int		i;
	t_piece *current_piece;

	current_piece = *stock;
	i = 0;
	if (x == -1)
		return (-1);
	if ((*squ) != NULL)
	{
		while ((*squ)[i])
			free((*squ)[i++]);
		free((*squ));
	}
	if (!((*squ) = (char**)malloc(sizeof(char*) * x + 1)))
		return (-1);
	(*squ)[x] = NULL;
	if (putpoints(squ, i, x) == -1)
		return (-1);
	if (trypiece(x, squ, 0, current_piece) == 0)
		put_tab(x + 1, stock, squ);
	return (0);
}

static int		security(const int fd)
{
	if (fd == -1)
		ft_putendl("error");
	else
	{
		if (close(fd) == -1)
			ft_putendl("error");
		else
			ft_putendl("error");
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	**squ;
	t_piece	*stock;
	char	*str;

	stock = NULL;
	squ = NULL;
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (1);
	}
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
		return (security(fd));
	if (checklines(&stock, fd, &str) == -1)
		return (security(fd));
	if (put_tab(putosquareroot(&stock), &stock, &squ) == -1)
		return (security(fd));
	if (close(fd) == -1)
		ft_putendl("error");
	print_free(&squ, &str, &stock);
	return (0);
}
