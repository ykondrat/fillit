/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:10:54 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 15:34:13 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit [file name]\n", 28);
		exit(0);
	}
}

void	ft_open_error_fd(int fd)
{
	if (fd < 0)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_valid_on_sharp(char **array)
{
	int		row;
	int		col;
	int		sharp;
	int		dot;

	row = 0;
	while (array[row])
	{
		sharp = 0;
		dot = 0;
		col = 0;
		while (array[row][col])
		{
			if (array[row][col] == '.')
				dot++;
			if (array[row][col] == '#')
				sharp++;
			col++;
		}
		if (dot != 12 && sharp != 4)
			ft_error();
		row++;
	}
}
