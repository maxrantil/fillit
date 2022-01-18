/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:08 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/18 14:04:41 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read_file(int fd, char **copy_of_file)
{
	t_r_var	pni;

	pni.count = 0;
	pni.readret = 1;
	pni.temp2 = ft_strnew(BUFF_SIZE);
	pni.temp3 = ft_strnew(BUFF_SIZE);
	pni.buffer = ft_strnew(BUFF_SIZE);
	while (pni.readret)
	{
		if (pni.readret == -1)
			return (-1);
		pni.readret = read(fd, pni.buffer, BUFF_SIZE);
		ft_strdel(&pni.temp2);
		pni.temp2 = ft_strjoin(pni.temp3, pni.buffer);
		ft_strdel(&pni.temp3);
		pni.temp3 = ft_strdup(pni.temp2);
		ft_bzero(pni.buffer, ft_strlen(pni.buffer));
		pni.count++;
	}
	*copy_of_file = pni.temp3;
	ft_strdel(&pni.temp2);
	ft_strdel(&pni.buffer);
	return (pni.count);
}

char	**ft_malloc_tetrominos(int count)
{
	int		i;
	char	**tetrominos;

	if (count == -1)
		ft_putstr("error, reading failed, fd not valid\n");
	tetrominos = (char **)malloc(sizeof(char *) * count);
	i = 0;
	while (i < count)
	{
		tetrominos[i] = ft_strnew(BUFF_SIZE);
		i++;
	}
	return (tetrominos);
}

void	ft_divide_pieces(char *pieces, char **tetrominos)
{
	t_ints0	index;

	index.i = 0;
	index.x = 0;
	index.y = 0;
	index.len = ft_strlen(pieces);
	while (index.i < index.len)
	{
		if (pieces[index.i] == '\n' && pieces[index.i + 1] == '\n')
		{
			index.i = index.i + 2;
			index.x++;
			index.y = 0;
		}
		tetrominos[index.x][index.y] = pieces[index.i];
		index.i++;
		index.y++;
	}
	tetrominos[index.x][index.y - 1] = '\0';
}

int	ft_verify_file(char *copy_of_file, char	**tetrominos)
{
	if (copy_of_file[ft_strlen(copy_of_file) - 1] != '\n')
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 2] != '.'
		&& copy_of_file[ft_strlen(copy_of_file) - 2] != '#')
		return (-1);
	ft_divide_pieces(copy_of_file, tetrominos);
	if (ft_verify_pieces(tetrominos) == -1)
		ft_putstr("error, piece not valid\n");
	if (ft_verify_pieces_two(tetrominos) == -1)
		ft_putstr("error, piece not valid\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*copy_of_file;
	char	**tetrominos;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetrominos = ft_malloc_tetrominos(ft_read_file(fd, &copy_of_file));
		if (ft_verify_file(copy_of_file, tetrominos) == -1)
			ft_putstr("error, file not valid\n");
		ft_strdel(&copy_of_file);
		ft_map_generator(tetrominos);
	}
	return (0);
}
