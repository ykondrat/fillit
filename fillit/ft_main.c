/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:11:05 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 15:17:27 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*str;
	char		**array;
	char		**field;
	t_tetris	*tetris;

	ft_error_argc(argc);
	str = ft_read_file(argv[1]);
	if (!str || ft_count_tetriminos(str) > 26)
		ft_error();
	array = ft_create_array(str, 0, 0, 0);
	ft_valid_tetriminos(array, 0, 0, 0);
	ft_last_valid(array);
	tetris = ft_create_struct(array);
	field = ft_create_field(tetris, ft_field_size(tetris));
	ft_print_result(field);
	free(str);
	ft_free_array(array);
	ft_free_array(field);
	ft_free_list_str(tetris);
	ft_free_list(&tetris);
	return (0);
}
