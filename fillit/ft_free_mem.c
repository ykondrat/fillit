/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:09:57 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 14:02:10 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_list_str(t_tetris *tetris)
{
	t_tetris	*tmp;
	t_tetris	*buf;

	tmp = tetris;
	while (tmp)
	{
		buf = tmp;
		buf->str = NULL;
		free(buf->str);
		tmp = tmp->next;
	}
}

void	ft_free_list(t_tetris **tetris)
{
	t_tetris	*tmp;

	while (*tetris)
	{
		tmp = *tetris;
		tmp = NULL;
		free(tmp);
		*tetris = (*tetris)->next;
	}
	*tetris = NULL;
}
