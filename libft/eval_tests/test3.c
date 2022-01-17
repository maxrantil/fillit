/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:52:52 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/29 20:07:40 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED(...) printf("\033[;31m" __VA_ARGS__)
#define GREEN(...) printf("\033[0;32m" __VA_ARGS__)
#define CYAN(...) printf("\033[0;36m" __VA_ARGS__)
#define RESET(...) printf("\033[0m" __VA_ARGS__)

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	//ft_memcpy
	
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 30)))
		return (0);
	ft_memset(mem, '*', 30);
	
	if (mem == ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
	{
		if (mem == ft_memcpy(mem, "zyxwvutst", 0))
		{
			if (mem == ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
			{
				printf("ft_memcpy	TEST ");
				GREEN("OK\n");
				RESET();
			}
		}
	}
	else
	{
		printf("ft_memcpy	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_strcpy
	
	char *str_strcpy[] = {"cpy this str", "das\0assd\0", "  \t \0 \t  ", "         ", "yes", "OK"};
  	char dst_strcpy[19];
	char dst1_strcpy[19];
	int		i = 0;

	while (i < 5 && strcmp(str_strcpy[i], strcpy(dst_strcpy, str_strcpy[i])) == strcmp(str_strcpy[i], ft_strcpy(dst1_strcpy, str_strcpy[i])))
		i++;
	if (i == 5)
	{
		printf("ft_strcpy	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", i, i);
	}
	else
	{
		printf("ft_strcpy	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_strcat
	
	i = 0;
	int	count = 0;
	char	*cat1;  
	char	*cat2;
	cat1 = (char *)ft_memalloc(sizeof(char) * 100);
	if (!cat1)
		return (0);
	cat2 = (char *)ft_memalloc(sizeof(char) * 100);
	if (!cat2)
		return (0);
	const	char *str[] = {"cpy str", "abcdaaaaaaaaaa", "\0\0\0\0\0\0\0\0", "\t \0  \v ", "     \0   \0", "yes"};

	const	char *str1[] = {"cpy str", "abcdaaaaaaaaaa", "\0\0\0\0\0\0\0\0", "\t \0  \v ", "     \0   \0", "yes"};
	char *s1;
	char *s2;

	while (i < 5)
	{
		s1 = ft_strcat(cat1, str[i]);
		s2 = strcat(cat2, str1[i]);
		if (strcmp(s1, s2) == 0)
			count++;
		i++;
	}
	if (count == 5)
	{
		printf("ft_strcat	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", i, i);
	}
	else
	{
		printf("ft_strcat	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_strcmp
	
	i = 0;

 	char *cmp_stri[] = {"cmp this str to str1", "", "\0", "\t \v        \t     \0    \0   \0"};

	while (i < 4 && strcmp(cmp_stri[i], cmp_stri[i + 1]) == ft_strcmp(cmp_stri[i], cmp_stri[i + 1]))
		i++;
	if (i == 4)
	{
		printf("ft_strcmp	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", i, i);
	}
	else
	{
		printf("ft_strcmp	TEST ");
		RED("NOT OK, %d failed \n", i);
		RESET();
	}
	ft_putchar('\n');

	//ft_strstr
	
	i = 0;
 	const char *ss_str2[] = {"srdub stthrstrirs str is a much", "str", "mug", "", "  "};
	while (i < 4 && strstr(ss_str2[i], ss_str2[i + 1]) == ft_strstr(ss_str2[i], ss_str2[i + 1]))
		i++;
	if (i == 4)
	{
		printf("ft_strstr	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", i, i);
	}
	else
	{
		printf("ft_strstr	TEST ");
		RED("NOT OK, %d failed \n", i);
		RESET();
	}
	ft_putchar('\n');

	//ft_memmove
	
	char memmove_str1[] = "stackoverflow";
    char memmove_str2[] = "stackoverflow";

    int y = 0;
	void	*p1;
	void	*p2;

    p1 = memmove(memmove_str1 + 5, memmove_str1, y);
    p2 = ft_memmove(memmove_str2 + 5, memmove_str2, y);
	while (y < 10 && 0 == strcmp((char *)p1, (char *)p2))
		y++;
	if (y == 10)
	{
		printf("ft_memmove	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", y, y);
	}
	else
	{
		printf("ft_memmove	TEST ");
		RED("NOT OK, %d failed \n", y);
		RESET();
	}
	ft_putchar('\n');

	//ft_memcmp
	
	i = 0;
	char *memcmp_stri[] = {"cm1p this str to str1", "cmp1 this str to str2", "cmp 1this str to str3", "cmp t1his str to str4"};
	char *memcmp_str1[] = {"cm1p this str to str1", "cmp1 this str to str2", "cmp 1this str to str3", "cmp t1his str to str4"};

	while (i < 3 && memcmp(memcmp_stri[i], memcmp_stri[i + 1], i) == ft_memcmp(memcmp_str1[i], memcmp_str1[i + 1], i))
		i++;
	if (i == 3)
	{
		printf("ft_memcmp	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", i + 1, i + 1);
	}
	else
	{
		printf("ft_memcmp	TEST ");
		RED("NOT OK, %d failed \n", i);
		RESET();
	}
	ft_putchar('\n');

	return (0);


}
