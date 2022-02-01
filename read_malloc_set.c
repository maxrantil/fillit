/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_malloc_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:02:10 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 13:43:59 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**set_tm(t_struct i, char *tm_buf, char **tm_blocks)
{
	i.t = 0;
	i.y = 0;
	i.x = 0;
	while (i.t < i.len)
	{
		if (tm_buf[i.t] == '\n' && tm_buf[i.t + 1] == '\n')
		{
			i.t += 2;
			i.x++;
			i.y = 0;
		}
		tm_blocks[i.x][i.y++] = tm_buf[i.t++];
	}
	tm_blocks[i.x][i.y - 1] = '\0';
	return (tm_blocks);
}

char	**malloc_tm(int count, char *tm_buf)
{
	t_struct	i;
	char		**tm_blocks;

	if (count == -1 || count > 27)
		return (NULL);
	tm_blocks = (char **)malloc(sizeof(char *) * count);
	if (!tm_blocks)
		return (NULL);
	i.len = ft_strlen(tm_buf);
	i.i = 0;
	while (count--)
		tm_blocks[i.i++] = ft_strnew(BUFF_SIZE);
	return (set_tm(i, tm_buf, tm_blocks));
}

int	verify_pieces(char	**tetrominos)
{
	if (verify_pieces_one(0, 0, tetrominos) == -1
		|| verify_pieces_two(0, 0, 0, tetrominos) == -1)
		return (-1);
	return (0);
}

static int	verify_file(char *copy_of_file)
{
	if (no_dots(copy_of_file) == -1
		|| copy_of_file[ft_strlen(copy_of_file) - 1] != '\n'
		|| (copy_of_file[ft_strlen(copy_of_file) - 2] != '.'
			&& copy_of_file[ft_strlen(copy_of_file) - 2] != '#'))
		return (-1);
	return (0);
}

int	read_file(int count, int fd, char **copy_of_file)
{
	char	read_buf[BUFF_SIZE + 1];
	char	*tm_buf;
	ssize_t	read_ret;

	read_ret = 1;
	tm_buf = ft_strnew(BUFF_SIZE);
	while (read_ret && ++count)
	{
		if ((read_ret != 0 && read_ret != 1 && read_ret != 20
				&& read_ret != 21) || read_ret == -1)
		{
			ft_strdel(&tm_buf);
			return (-1);
		}
		read_ret = read(fd, read_buf, BUFF_SIZE);
		read_buf[read_ret] = '\0';
		tm_buf = ft_strupdate(tm_buf, read_buf);
	}
	*copy_of_file = ft_strdup(tm_buf);
	ft_strdel(&tm_buf);
	if (verify_file(*copy_of_file) == -1)
		return (error_main(*copy_of_file));
	return (count);
}
