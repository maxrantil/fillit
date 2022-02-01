/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_malloc_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:02:10 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 14:51:26 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**set_tm(int y, int x, char *tm_buf, char **tm_blocks)
{
	size_t	len;
	size_t	t;

	t = 0;
	len = ft_strlen(tm_buf);
	while (t < len)
	{
		if (tm_buf[t] == '\n' && tm_buf[t + 1] == '\n')
		{
			t += 2;
			x++;
			y = 0;
		}
		tm_blocks[x][y++] = tm_buf[t++];
	}
	tm_blocks[x][y - 1] = '\0';
	return (tm_blocks);
}

char	**malloc_tm(int i, int count, char *tm_buf)
{
	char		**tm_blocks;

	if (count == -1 || count > 27)
		return (NULL);
	tm_blocks = (char **)malloc(sizeof(char *) * count);
	if (!tm_blocks)
		return (NULL);
	while (count--)
		tm_blocks[i++] = ft_strnew(BUFF_SIZE);
	return (set_tm(0, 0, tm_buf, tm_blocks));
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
