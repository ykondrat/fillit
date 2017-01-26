/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:11:20 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/14 11:06:46 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_delete_tetris(char **field, t_tetris *tetris, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (field[y][x] == tetris->chr)
				field[y][x] = '.';
			x++;
		}
		y++;
	}
	return (field);
}

static char	**ft_set_tetri_field(char **field, t_tetris *tetris, int size)
{
	int		x;
	int		y;
	int		index;

	y = 0;
	index = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetris->x[index] == x && tetris->y[index] == y)
			{
				field[y][x] = tetris->chr;
				index++;
			}
			x++;
		}
		y++;
	}
	return (field);
}

static int	ft_check_field(char **field, t_tetris *tetris, int size)
{
	int		x;
	int		y;
	int		index;

	y = 0;
	index = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetris->x[index] == x &&
					tetris->y[index] == y && field[y][x] != '.')
				return (0);
			else if (tetris->x[index] == x && tetris->y[index] == y)
				index++;
			x++;
		}
		y++;
	}
	if (index < 4)
		return (0);
	return (1);
}

char		**ft_solve_tetris(char **field, t_tetris *tetris, int size)
{
	int		row;
	int		col;
	char	**tmp;

	if (!tetris->next)
		return (field);
	tmp = NULL;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			tetris = ft_coord_field(tetris, col, row, size);
			if (ft_check_field(field, tetris, size))
				tmp = ft_solve_tetris(ft_set_tetri_field(field, tetris, size),
						tetris->next, size);
			if (tmp)
				return (tmp);
			field = ft_delete_tetris(field, tetris, size);
			col++;
		}
		row++;
	}
	return (NULL);
}
