/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:09:24 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 13:55:27 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_field_size(t_tetris *tetris)
{
	int		i;
	int		size;

	i = 0;
	size = 2;
	while (tetris->next)
	{
		tetris = tetris->next;
		i++;
	}
	while (size * size < i * 4)
		size++;
	return (size);
}

static char	**ft_empty_field(char **field, int size)
{
	int y;
	int x;

	y = 0;
	if (!(field = (char**)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		if (!(field[y] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		x = 0;
		while (x < size)
		{
			field[y][x] = '.';
			x++;
		}
		field[y][x] = '\0';
		y++;
	}
	field[y] = NULL;
	return (field);
}

char		**ft_create_field(t_tetris *tetris, int size)
{
	char	**field;

	field = NULL;
	while (!field)
	{
		field = ft_empty_field(field, size);
		field = ft_solve_tetris(field, tetris, size);
		size++;
	}
	return (field);
}
