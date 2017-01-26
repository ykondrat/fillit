/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:10:39 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 15:13:45 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t index;

	index = 0;
	while (index < size && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	while (index < size)
	{
		dest[index] = '\0';
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char		*ft_strndup(const char *str, size_t size)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest = ft_strncpy(dest, str, size);
	return (dest);
}

void		ft_putendl(char const *str)
{
	int index;

	if (str)
	{
		index = 0;
		while (str[index])
			write(1, &str[index++], 1);
		write(1, "\n", 1);
	}
}

void		ft_last_valid(char **array)
{
	int	row;
	int	col;
	int	elem;

	row = 0;
	elem = 0;
	while (array[row])
	{
		col = 0;
		while (array[row][col])
		{
			if (array[row][col] != '\n')
				elem++;
			if (array[row][col] == '\n')
			{
				if (elem != 4)
					ft_error();
				else
					elem = 0;
			}
			col++;
		}
		row++;
	}
}

void		ft_print_result(char **field)
{
	int	i;

	i = 0;
	while (field[i])
		ft_putendl(field[i++]);
}
