/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:08 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/19 15:11:25 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_read_file(int fd, char **copy_of_file)
{
	t_r_var	pni;

	pni.count = 0;
	pni.readret = 1;
	pni.temp2 = ft_strnew(BUFF_SIZE);
	pni.temp3 = ft_strnew(BUFF_SIZE);
	pni.buffer = ft_strnew(BUFF_SIZE);
	while (pni.readret)
	{
		if ((pni.readret != 0 && pni.readret != 1 && pni.readret != 20
				&& pni.readret != 21) || pni.readret == -1)
		{
			ft_free_read(pni);
			return (-1);
		}
		pni.readret = read(fd, pni.buffer, BUFF_SIZE);
		ft_strdel(&pni.temp2);
		pni.temp2 = ft_strupdate(pni.temp3, pni.buffer);
		pni.temp3 = ft_strdup(pni.temp2);
		ft_bzero(pni.buffer, ft_strlen(pni.buffer));
		pni.count++;
	}
	*copy_of_file = ft_strdup(pni.temp3);
	ft_free_read(pni);
	return (pni.count);
}

static char	**ft_malloc_tetrominos(int count)
{
	int		i;
	char	**tetrominos;

	if (count == -1 || count > 27)
		return (NULL);
	tetrominos = (char **)malloc(sizeof(char *) * count);
	if (!tetrominos)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tetrominos[i] = ft_strnew(BUFF_SIZE);
		i++;
	}
	return (tetrominos);
}

static void	ft_divide_pieces(char *copy_of_file, char **tetrominos)
{
	t_ints0	index;

	index.i = 0;
	index.x = 0;
	index.y = 0;
	index.len = ft_strlen(copy_of_file);
	while (index.i < index.len)
	{
		if (copy_of_file[index.i] == '\n' && copy_of_file[index.i + 1] == '\n')
		{
			index.i = index.i + 2;
			index.x++;
			index.y = 0;
		}
		tetrominos[index.x][index.y] = copy_of_file[index.i];
		index.i++;
		index.y++;
	}
	tetrominos[index.x][index.y - 1] = '\0';
}

static int	ft_verify_file(char *copy_of_file, char	**tetrominos)
{
	if (ft_no_dots(copy_of_file) == -1)
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 1] != '\n')
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 2] != '.'
		&& copy_of_file[ft_strlen(copy_of_file) - 2] != '#')
		return (-1);
	ft_divide_pieces(copy_of_file, tetrominos);
	if (ft_verify_pieces(tetrominos) == -1)
		return (-1);
	if (ft_verify_pieces_two(tetrominos) == -1)
		return (-1);
	return (0);
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
		tm = ft_malloc_tetrominos(ft_read_file(fd, &copy_of_file));
		if (close(fd) == -1)
			return (ft_errormain(copy_of_file));
		if (tm == NULL || ft_verify_file(copy_of_file, tm) == -1)
			return (ft_errormain(copy_of_file));
		ft_strdel(&copy_of_file);
		ft_map_generator(tm);
	}
	else
	{
		ft_putstr("usage: \tamount of arguments is not 1\n");
		return (1);
	}
	return (0);
}
