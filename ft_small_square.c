
#include "fillit.h"

int	*ft_small_square(char **tetrominos, int i, int x, int add)
{

	static int	square[4];
	if (i == 2)
		add = -2;
	if (i == 3)
		add = -1;
	square[0] = 0;
	square[1] = 1;
	square[2] = 5 + add;
	square[3] = 6 + add;
	i = 0;
	while (tetrominos[x][i] == '.' || tetrominos[x][i] == '\n')
		i++;
	if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 6] == '2')
		return (square);
	else
		return(ft_i(tetrominos, i, x, add));
}