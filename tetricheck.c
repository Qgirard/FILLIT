/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetricheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:33:17 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 15:51:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		checkdiez(char *str, int check, int i, int j)
{
	if (str[i + 1] == '#' && j < 15 && j != 3 && j != 7 && j != 11)
		check++;
	if (str[i + 4] == '#' && j < 12)
		check++;
	if (str[i - 1] == '#' && j > 0 && j != 4 && j != 8 && j != 12)
		check++;
	if (str[i - 4] == '#' && j > 3)
		check++;
	return (check);
}

int				tetricheck(char *str)
{
	int i;
	int j;
	int check;

	i = 0;
	while (str[i])
	{
		check = 0;
		j = 0;
		while (j < 16)
		{
			if (str[i] == '#')
				check = checkdiez(str, check, i, j);
			j++;
			i++;
		}
		if (check != 6 && check != 8)
			return (-1);
	}
	return (0);
}
