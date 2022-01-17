#include "fillit.h"

int	*ft_error()
{
	static int error[4];
	error[0] = 9;
	error[1] = 9;
	error[2] = 9;
	error[3] = 9;
	

	return (error);
}

int	*ft_t_2(char **tetrominos, int i, int x, int add)
{
	static int	vertical_t_left[4];
	vertical_t_left[0] = 1;
	vertical_t_left[1] = 5 + add;
	vertical_t_left[2] = 6 + add;
	vertical_t_left[3] = 11 + add + add;

	static int	vertical_t_right[4];
	vertical_t_right[0] = 0;
	vertical_t_right[1] = 5 + add;
	vertical_t_right[2] = 6 + add;
	vertical_t_right[3] = 10 + add + add;
	
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '1'
		&& tetrominos[x][i + 5] == '3' && tetrominos[x][i + 10] == '1')
		return (vertical_t_left);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '3'
		&& tetrominos[x][i + 6] == '1' && tetrominos[x][i + 10] == '1')
		return (vertical_t_right);
	else
		return(ft_error());
}