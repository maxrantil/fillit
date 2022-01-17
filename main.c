/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilot <pilot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:08 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/12 11:33:37 by pilot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
