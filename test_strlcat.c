/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:26:59 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/12 21:40:08 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "ft_strlcat.c"
#include <string.h>
#include <unistd.h>

int main()
{
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) -1. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, -1), strlcat(dest2, src, -1), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 0. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 0), strlcat(dest2, src, 0), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 9. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 9), strlcat(dest2, src, 9), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 10. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 10), strlcat(dest2, src, 10), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 11. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 11), strlcat(dest2, src, 11), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 12. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 12), strlcat(dest2, src, 12), dest, dest2);
	}
	{
		char src[] = ""; char dest[11]; char dest2[11];
		printf("Test: empty empty(11) -1. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, -1), strlcat(dest2, src, -1), dest, dest2);
	}
	{
		char src[] = ""; char dest[11]; char dest2[11];
		printf("Test: empty empty(11) 0. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 0), strlcat(dest2, src, 0), dest, dest2);
	}
	{
		char src[] = ""; char dest[11]; char dest2[11];
		printf("Test: empty empty(11) 1. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 1), strlcat(dest2, src, 1), dest, dest2);
	}
	{
		char src[] = ""; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: empty Hello(11) 1. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 1), strlcat(dest2, src, 1), dest, dest2);
	}
	{
		char src[] = ""; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: empty Hello(11) 2. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 2), strlcat(dest2, src, 2), dest, dest2);
	}
	{
		char src[] = "World"; char dest[7] = {'H','e','l','l','o'}; char dest2[7] = {'H','e','l','l','o'};
		printf("Test: World Hello(7) 11. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 11), strlcat(dest2, src, 11), dest, dest2);
	}
	{
		char src[] = "World"; char dest[6] = {'H','e','l','l','o'}; char dest2[6] = {'H','e','l','l','o'};
		printf("Test: World Hello(6) 11. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 11), strlcat(dest2, src, 11), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Test: World Hello(11) 13. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 13), strlcat(dest2, src, 13), dest, dest2);
	}
	{
		char src[] = "World"; char dest[13] = {'H','e','l','l','o'}; char dest2[13] = {'H','e','l','l','o'};
		printf("Test: World Hello(13) 13. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 13), strlcat(dest2, src, 13), dest, dest2);
	}
	//chat gpt additional test cases
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Edge Case: World Hello(11) 1. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 1), strlcat(dest2, src, 1), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Edge Case: World Hello(11) 5. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 5), strlcat(dest2, src, 5), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o','W','o','r','l','d'}; char dest2[11] = {'H','e','l','l','o','W','o','r','l','d'};
		printf("Edge Case: World HelloWorld(11) 10, non-null-terminated. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 10), strlcat(dest2, src, 10), dest, dest2);
	}
	{
		char src[] = ""; char dest[11] = {}; char dest2[11] = {};
		printf("Edge Case: empty empty(11) 15. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 15), strlcat(dest2, src, 15), dest, dest2);
	}
	{
		char src[] = "World"; char dest[11] = {'H','e','l','l','o','W','o','r','l','d','!'}; char dest2[11] = {'H','e','l','l','o','W','o','r','l','d','!'};
		printf("Edge Case: World HelloWorld!(11) 15. Result: %zu | %zu String: \"%s\" | \"%s\" - buffer overflow, unexpected behavior\n\n", ft_strlcat(dest, src, 15), strlcat(dest2, src, 15), dest, dest2);
	}
	{
		char src[] = "ThisIsAVeryLargeStringThatExceedsBufferSize"; char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		printf("Edge Case: large string  Hello(11) 11. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(dest, src, 11), strlcat(dest2, src, 11), dest, dest2);
	}
	{
		char dest[15]; char dest2[15];
		memset(dest, 'r', 15); memset(dest2, 'r', 15);
		printf("WarMachine test 7 that fails.:\nExpected result:\n31\nrrrrrrrrrrrrrrr\nft_strlcat & strlcat results:\n%zu | %zu\n", 
		ft_strlcat(dest, "lorem ipsum dolor sit amet", 5), strlcat(dest, "lorem ipsum dolor sit amet", 5));
		/* write(1, "\n", 1); */
		write(1, dest, 15);
		write(1, " | ", 3);
		write(1, dest2, 15);
	}
	/*{ //-segfaults
		char src[] = "ThisIsAVeryLargeStringThatExceedsBufferSize"; //char dest[11] = {'H','e','l','l','o'}; char dest2[11] = {'H','e','l','l','o'};
		//printf("Edge Case: null. Result: %zu | %zu String: \"%s\" | \"%s\"\n\n", ft_strlcat(NULL, NULL, 11), strlcat(NULL, NULL, 11), NULL, NULL);
		ft_strlcat(src, NULL, 11);
		printf("%s\n\n", src);
	}*/


	return 0;
}
