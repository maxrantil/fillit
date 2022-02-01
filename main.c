/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:08 by llonnrot          #+#    #+#             */
/*   Updated: 2022/02/01 14:24:12 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*copy_of_file;
	char	**tm;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (error_fd());
		tm = malloc_tm(read_file(0, fd, &copy_of_file), copy_of_file);
		if (tm == NULL || close(fd) == -1 || verify_pieces(tm) == -1)
			return (error_main(copy_of_file));
		ft_strdel(&copy_of_file);
		map_generator(0, 0, 0, tm);
	}
	else
	{
		ft_putstr("usage: \t./fillit <file>\n");
		return (1);
	}
	return (0);
}
