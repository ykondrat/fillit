/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:10:06 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/14 11:04:59 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetriminos(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '\n' && (str[index + 1] == '\n' ||
					str[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}

char	*ft_create_str(int fd)
{
	char	buf[BUF_SIZE];
	char	*str;
	int		index;
	int		ret;

	if ((ret = (int)read(fd, buf, BUF_SIZE)))
	{
		if (!(str = (char*)malloc(sizeof(char) * ret + 1)))
			return (NULL);
		index = 0;
		while (index < ret)
		{
			if ((buf[index] == '.' || buf[index] == '#' || buf[index] == '\n')
	&& (buf[ret - 1] == '\n' && (buf[ret - 2] == '.' || buf[ret - 2] == '#')))
			{
				str[index] = buf[index];
				index++;
			}
			else
				ft_error();
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}

char	**ft_create_array(char *str, int index, int row, int col)
{
	char	**array;

	if (str)
	{
		if (!(array = (char**)malloc(sizeof(char*)
						* ft_count_tetriminos(str) + 1)))
			return (NULL);
		while (str[index] && row < ft_count_tetriminos(str))
		{
			col = 0;
			if (!(array[row] = (char*)malloc(sizeof(char) * 21)))
				return (NULL);
			while (col < 20)
				array[row][col++] = str[index++];
			if (!((str[index] == '\n' || str[index] == '\0')
						&& str[index - 1] == '\n'))
				ft_error();
			array[row++][col] = '\0';
			index++;
		}
		array[row] = NULL;
		return (array);
	}
	return (NULL);
}

void	ft_valid_tetriminos(char **array, int row, int col, int con)
{
	while (array[row])
	{
		col = 0;
		con = 0;
		while (array[row][col])
		{
			if (array[row][col] == '#')
			{
				if (array[row][col + 1] == '#' && col + 1 < 20)
					con++;
				if (array[row][col + 5] == '#' && col + 5 < 20)
					con++;
				if (array[row][col - 1] == '#' && col - 1 >= 0)
					con++;
				if (array[row][col - 5] == '#' && col - 5 >= 0)
					con++;
			}
			col++;
		}
		row++;
		if (!(con == 6 || con == 8))
			ft_error();
	}
	ft_valid_on_sharp(array);
}

char	*ft_read_file(char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY);
	ft_open_error_fd(fd);
	str = ft_create_str(fd);
	if (close(fd) == -1)
		ft_error();
	return (str);
}
