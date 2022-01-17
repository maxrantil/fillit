/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:17 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/02 17:55:25 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED(...) printf("\033[;31m" __VA_ARGS__)
#define GREEN(...) printf("\033[0;32m" __VA_ARGS__)
#define CYAN(...) printf("\033[0;36m" __VA_ARGS__)
#define RESET(...) printf("\033[0m" __VA_ARGS__)

#include <stdio.h>
#include "libft.h"

/*- ft_strlcat
**- ft_strdup
**- ft_atoi
**- ft_memccpy
**- ft_strnstr
**- ft_strncmp
**- ft_strncpy
**- ft_strncat
*/
size_t	test_ft_strlcat()
{
	char str1[] = "a potentially long string";

    char dest[50] = "This is ";
    char dest2[50] = "This is ";
    size_t n = 16;
	size_t	count = 0;
    int a = ft_strlcat(dest, str1, n);
    int b = strlcat(dest2, str1, n);

	while (n > 0  && a == b)
	{
		n--;
    	a = ft_strlcat(dest, str1, n);
    	b = strlcat(dest2, str1, n);
		count++;
	}
	if (count == 16)
	{
		printf("ft_strlcat	TEST ");
		GREEN("OK");
		RESET("	(%zu of %zu complete)\n", count, count);
	}
	else
	{
		printf("ft_strlcat	TEST ");
		RED("NOT OK\n");
		RESET();
	}

	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	size_t r1 = __builtin___strlcat_chk (buff1, str, max, __builtin_object_size (buff1, 2 > 1 ? 1 : 0));
	size_t r2 = ft_strlcat(buff2, str, max);

	if (r1 != r2)
		ft_putendl("Test Failed");
	char s1[4] = "";
	char s2[4] = "";
	r1 = __builtin___strlcat_chk (s1, "thx to ntoniolo for this test !", 4, __builtin_object_size (s1, 2 > 1 ? 1 : 0))
		;
	r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4)
		;
	if (r1 != r2)
		RED("extra Test Failed\n");
	GREEN("extra Test Succed\n");
	RESET();

    return (0);
}

size_t	test_ft_strdup()
{
  	const char str2[58] = "dub st thris str is a much";
  	const char str3[18] = "str";
	const char str4[18] = "mug";
	const char str5[15] = "";
	char dst2[13];

	int	test = 0;
	
	if (0 == strcmp(ft_strdup(str3), strdup(str3)))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (0 == strcmp(ft_strdup(str4), strdup(str4)))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (0 == strcmp(ft_strdup(str5), strdup(str5)))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (test == 3)
	{
		printf("ft_strdup	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", test, test);
	}
	else
	{
		printf("ft_strdup	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	return 0;
}

int	test_ft_atoi(void)
{
	int	test = 0;

	if (ft_atoi("1000") == atoi("1000"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("-1000") == atoi("-1000"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("0") == atoi("0"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("-123abc123") == atoi("-123abc123"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("") == atoi(""))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("aa") == atoi("aa"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("-9999999999999999999") == atoi("-9999999999999999999"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}
	if (ft_atoi("+99999999999999999999999") == atoi("+99999999999999999999999"))
		test++;
	else 
	{
		RED("Test %d NOT OK\n", test);
        RESET();
	}		
	if (test == 9)
	{
		printf("ft_atoi		TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", test, test);
	}
	else
	{
		printf("ft_atoi		TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	return 0;
}

int	test_ft_memccpy(void)
{
	void    *mem;
    void    *membis;
	void	*mem1;
	void	*membis1;
	int		test = 0;

	if (!(mem = malloc(sizeof(*mem) * 30)))
        return (0);
    
	ft_memset(mem, '*', 29);
    ((char*)mem)[29] = '\0';

    membis = mem;
	if (!(mem = ft_memccpy(mem, "0yxwvutsrqponmlkjihgfedcba", 'r', 20)))
	{
		printf("ft_memccpy		TEST ");
		RED("NOT OK (1yx)\n");
		RESET();
	}
	else
		test++;
	if (!(mem1 = malloc(sizeof(*mem1) * 30)))
		return (0);
	ft_memset(mem1, '*', 29);
    ((char*)mem1)[29] = '\0';
	membis1 = mem1;
    if (!(mem1 = ft_memccpy(mem1, "1yxwvutsrqponmlkjihgfedcba", 'r', 3)))
		test++;
	else
	{
		printf("ft_memccpy		TEST ");
		RED("NOT OK (1yx)\n");
		RESET();
	}
	if (test == 2)
	{
		printf("ft_memccpy	TEST ");
		GREEN("OK");
		RESET("	(%d of %d complete)\n", test, test);
	}
	ft_putchar('\n');

    return (0);
}

int	test_ft_strnstr(void)
{
    char *s1 = "MZIRIBMZIRIBMZE123";
    char *s2 = "MZIRIBMZE";
    size_t max = strlen(s2);
    char *i1 = strnstr(s1, s2, max);
    char *i2 = ft_strnstr(s1, s2, max);
	int	test = 0;

	if (i1 == i2)
		test++;
    else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK (MZIR)\n");
        RESET();
    }
	char	buf[10];
	if (ft_strnstr(buf, "deux", 5) == strnstr(buf, "deux", 5))
		test++;
	else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK (deux)\n");
        RESET();
    }
	char	buf2[] = "ozarabozaraboze123";
	if (ft_strnstr(buf2, "ozaraboze", 15) == strnstr(buf2, "ozaraboze", 15)) //"ozaraboze123") == 0);
		test++;
	else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK (ozar)\n");
        RESET();
    }
	char	buf3[10];
	bzero(buf3, 10);
	strcpy(buf3, "un deux 9");

	if(strcmp(ft_strnstr(buf3, "deux", 10), "deux 9") == 0)
		test++;
	else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK (deux 9)\n");
        RESET();
    }
	if (ft_strnstr(buf3, "9", 3) == NULL)
		test++;
	else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK ('9')\n");
        RESET();
    }
	if(strcmp(ft_strnstr(buf3, "", 6), buf3) == 0)
		test++;
	else
    {
        printf("ft_strnstr     TEST ");
        RED("NOT OK (empty)\n");
        RESET();
    }
	if (test == 6)
	{
        printf("ft_strnstr	TEST ");
        GREEN("OK");
        RESET(" (%d of %d complete)\n", test, test);
    }
	return 0;
}

int	main()
{
	test_ft_strlcat();
	test_ft_strdup();
	test_ft_atoi();
	test_ft_memccpy();
	test_ft_strnstr();
	return 0;
}
