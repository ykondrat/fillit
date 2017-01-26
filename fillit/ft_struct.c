/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:10:22 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 15:29:33 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*ft_coord_field(t_tetris *tetris, int x, int y, int size)
{
	int		index;
	int		min_x;
	int		min_y;

	index = 0;
	min_x = size;
	min_y = size;
	while (index < 4)
	{
		if (tetris->x[index] < min_x)
			min_x = tetris->x[index];
		if (tetris->y[index] < min_y)
			min_y = tetris->y[index];
		index++;
	}
	index = 0;
	while (index < 4)
	{
		tetris->x[index] = tetris->x[index] - min_x + x;
		tetris->y[index] = tetris->y[index] - min_y + y;
		index++;
	}
	return (tetris);
}

static t_tetris	*ft_search_sharp(t_tetris *tetris, char *str, int x, int y)
{
	int index;
	int t_index;

	index = 0;
	t_index = 0;
	while (str[index])
	{
		if (str[index] == '#')
		{
			tetris->x[t_index] = x;
			tetris->y[t_index] = y;
			t_index++;
		}
		x++;
		if (str[index] == '\n')
		{
			x = 0;
			y++;
		}
		index++;
	}
	return (tetris);
}

static t_tetris	*ft_set_coord(t_tetris *tetris)
{
	t_tetris	*tmp;

	tmp = tetris;
	while (tetris->next)
	{
		tetris = ft_search_sharp(tetris, tetris->str, 0, 0);
		tetris = tetris->next;
	}
	return (tmp);
}

t_tetris		*ft_create_struct(char **array)
{
	t_tetris	*tetris;
	t_tetris	*tmp;
	int			index;
	char		chr;

	if (!(tetris = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	tmp = tetris;
	index = 0;
	chr = 65;
	while (array[index])
	{
		tmp->str = ft_strndup(array[index], 20);
		tmp->chr = chr;
		index++;
		chr++;
		if (!(tmp->next = (t_tetris*)malloc(sizeof(t_tetris))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tetris = ft_set_coord(tetris);
	return (tetris);
}
