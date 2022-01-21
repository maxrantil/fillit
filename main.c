/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:08 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/21 15:20:05 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**malloc_and_set(int count, char *tm_buf)
{
	t_struct	i;
	char		**tm_blocks;

	if (count == -1 || count > 27)
		return (NULL);
	tm_blocks = (char **)malloc(sizeof(char *) * count);
	if (!tm_blocks)
		return (NULL);
	i.i = 0;
	i.len = ft_strlen(tm_buf);
	while (count--)
		tm_blocks[i.i++] = ft_strnew(BUFF_SIZE);
	while (i.t < i.len)
	{
		if (tm_buf[i.t] == '\n' && tm_buf[i.t + 1] == '\n')
		{
			i.t = i.t + 2;
			i.x++;
			i.y = 0;
		}
		tm_blocks[i.x][i.y++] = tm_buf[i.t++];
	}
	tm_blocks[i.x][i.y - 1] = '\0';
	return (tm_blocks);
}

static int	verify_pieces(char	**tetrominos)
{
	if (ft_verify_pieces(tetrominos) == -1)
		return (-1);
	if (ft_verify_pieces_two(tetrominos) == -1)
		return (-1);
	return (0);
}

static int	verify_file(char *copy_of_file)
{
	if (ft_no_dots(copy_of_file) == -1)
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 1] != '\n')
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 2] != '.'
		&& copy_of_file[ft_strlen(copy_of_file) - 2] != '#')
		return (-1);
	return (0);
}

static int	ft_read_file(int fd, char **copy_of_file)
{
	t_struct	r;
	char		read_buf[BUFF_SIZE + 1];

	r.read_ret = 1;
	r.count = 0;
	r.tm_buf = ft_strnew(BUFF_SIZE);
	while (r.read_ret)
	{
		if ((r.read_ret != 0 && r.read_ret != 1 && r.read_ret != 20
				&& r.read_ret != 21) || r.read_ret == -1)
		{
			ft_strdel(&r.tm_buf);
			return (-1);
		}
		r.read_ret = read(fd, read_buf, BUFF_SIZE);
		read_buf[r.read_ret] = '\0';
		r.tm_buf = ft_strupdate(r.tm_buf, read_buf);
		r.count++;
	}
	*copy_of_file = ft_strdup(r.tm_buf);
	ft_strdel(&r.tm_buf);
	if (verify_file(*copy_of_file) == -1)
		return (ft_errormain(*copy_of_file));
	return (r.count);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*copy_of_file;
	char	**tm;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_errorfd());
		tm = malloc_and_set(ft_read_file(fd, &copy_of_file), copy_of_file);
		if (tm == NULL || close(fd) == -1 || verify_pieces(tm) == -1)
			return (ft_errormain(copy_of_file));
		ft_strdel(&copy_of_file);
		ft_map_generator(tm);
	}
	else
	{
		ft_putstr("usage: \t./fillit <file>\n");
		return (1);
	}
	return (0);
}
