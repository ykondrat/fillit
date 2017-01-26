/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:09:02 by ykondrat          #+#    #+#             */
/*   Updated: 2017/01/13 15:31:04 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 546
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetris
{
	int				x[4];
	int				y[4];
	char			*str;
	char			chr;
	struct s_tetris	*next;
}					t_tetris;
void				ft_error(void);
char				*ft_create_str(int fd);
void				ft_error_argc(int argc);
void				ft_open_error_fd(int fd);
void				ft_free_array(char **array);
void				ft_putendl(char const *str);
void				ft_last_valid(char **array);
void				ft_print_result(char **field);
int					ft_count_tetriminos(char *str);
char				*ft_read_file(char *file_name);
void				ft_valid_on_sharp(char **array);
int					ft_field_size(t_tetris *tetris);
t_tetris			*ft_create_struct(char **array);
void				ft_free_list(t_tetris **tetris);
void				ft_free_list_str(t_tetris *tetris);
char				*ft_strndup(const char *str, size_t size);
char				**ft_create_field(t_tetris *tetris, int size);
char				**ft_create_array(char *str, int index, int row, int col);
t_tetris			*ft_coord_field(t_tetris *tetris, int x, int y, int size);
char				**ft_solve_tetris(char **field, t_tetris *tetris, int size);
void				ft_valid_tetriminos(char **array,
					int row, int col, int con);

#endif
