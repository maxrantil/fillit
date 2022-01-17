#define RED(...) printf("\033[;31m" __VA_ARGS__)
#define GREEN(...) printf("\033[0;32m" __VA_ARGS__)
#define CYAN(...) printf("\033[0;36m" __VA_ARGS__)
#define RESET(...) printf("\033[0m" __VA_ARGS__)

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main()
{
	//ft_toupper	

	int	atoupper = 'T';
	int	btoupper = 't';

	if (toupper(atoupper) == ft_toupper(atoupper))
	{
		printf("ft_toupper	TEST ");
		GREEN("OK\n");
		RESET();
	}
        else
	{
		RED("atoupper != 'T'\n");
		RESET();
	}
	if (toupper(btoupper) == ft_toupper(btoupper))
	{
		printf("ft_toupper	TEST ");
		GREEN("OK\n");
		RESET();
	}
	else
	{
		RED("btoupper != 't'\n");   
		RESET();					        
	}
	ft_putchar('\n');

	//ft_tolower
	
	int	atolower = 'T';
	int	btolower = 't';

	if (tolower(atolower) == ft_tolower(atolower))
	{
		printf("ft_tolower	TEST ");
		GREEN("OK\n");
		RESET();
	}
        else
	{
		RED("atolower != 'T'\n");
		RESET();
	}
	if (tolower(btolower) == ft_tolower(btolower))
	{
		printf("ft_tolower	TEST ");
		GREEN("OK\n");
		RESET();
	}
	else
	{
		RED("btolower != 't'\n");   
		RESET();					        
	}
	ft_putchar('\n');

	//ft_memchr
	
	char amemchr[] = "stackoverflow";
	char bmemchr[] = "stackoverflow";
	size_t cmemchr = 0;

	if (memchr(amemchr, 'o', cmemchr) == ft_memchr(bmemchr, 'o', cmemchr))
	{
		printf("ft_memchr	TEST ");
		GREEN("OK\n");
		RESET();
	}
        else
	{
		RED("cmemchr != 0\n");
		RESET();
	}
	cmemchr++;
	if (memchr(amemchr, 'k', cmemchr) == ft_memchr(bmemchr, 'k', cmemchr))
	{
		printf("ft_memchr	TEST ");
		GREEN("OK\n");
		RESET();
	}
        else
	{
		RED("cmemchr != 1\n");
		RESET();
	}
	cmemchr++;
	if (memchr(amemchr, 'v', cmemchr) == ft_memchr(bmemchr, 'v', cmemchr))
	{
		printf("ft_memchr	TEST ");
		GREEN("OK\n");
		RESET();
	}
        else
	{
		RED("cmemchr != 2\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_strchr
	
	char 	str_strchr[] = "Hello\0World";
	char	c_strchr = 0;

	while (c_strchr != 122)
	{
		if (ft_strchr(str_strchr, c_strchr) != strchr(str_strchr, c_strchr))
		{
			RED("ft_strchr != %c\n", c_strchr);
			RESET();
		}
		c_strchr++;
	}
	if (c_strchr == 122)
	{
		printf("ft_strchr	TEST ");
		GREEN("OK\n");
		RESET();
	}
	else
		printf("test not ended...\n");
	ft_putchar('\n');

	//ft_strrchr
	
	char 	str_strrchr[] = "Hello\0World";
	char	c_strrchr = 122;

	while (c_strrchr != 1)
	{
		if (ft_strrchr(str_strrchr, c_strrchr) != strrchr(str_strrchr, c_strrchr))
		{
			RED("ft_strrchr != %c\n", c_strrchr);
			RESET();
		}
		c_strrchr--;
	}
	if (c_strrchr == 1)
	{
		printf("ft_strrchr	TEST ");
		GREEN("OK\n");
		RESET();
	}
	else
	{
		printf("ft_strrchr	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_bzero
	
	char	str1_bzero[] = "Hello World";
	char	str2_bzero[] = "Hello World";
	int		v_bzero = 11;

	while (v_bzero != 0)
	{

		bzero(str2_bzero, v_bzero);
		ft_bzero(str1_bzero, v_bzero);
		bzero(str2_bzero, v_bzero);
		if (memcmp(str1_bzero, str2_bzero, v_bzero) != 0)
		{
			RED("ft_bzero != %d\n", v_bzero);
			RESET();
		}
		v_bzero--;
	}
	if (v_bzero == 0)
	{
		printf("ft_bzero	TEST ");
		GREEN("OK\n");
		RESET();
	}
	else
	{
		printf("ft_bzero	TEST ");
		RED("NOT OK\n");
		RESET();
	}
	ft_putchar('\n');


	return (0);

}
