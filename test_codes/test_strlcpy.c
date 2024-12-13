/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:25:56 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/12 19:29:33 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "../libft/ft_strlcpy.c"

int main()
{
    {
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 6\n");
        char src[] = "Hello World!"; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 6), strlcpy(dest2, src, 6), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 5\n");
        char src[] = "Hello World!"; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 5), strlcpy(dest2, src, 5), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 10\n");
        char src[] = "Hello World!"; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n", 
        ft_strlcpy(dest, src, 10), strlcpy(dest2, src, 10), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 8\n");
        char src[] = "Hello World!"; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n", 
        ft_strlcpy(dest, src, 8), strlcpy(dest2, src, 8), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 12\n");
        char src[] = "Hello World!"; char dest[20]; char dest2[20];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 12), strlcpy(dest2, src, 12), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 20\n");
        char src[] = "Hello World!"; char dest[20]; char dest2[20];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 20), strlcpy(dest2, src, 20), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[1], 1\n");
        char src[] = "Hello World!"; char dest[1]; char dest2[1];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 1), strlcpy(dest2, src, 1), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[1], 0\n");
        char src[] = "Hello World!"; char dest[1]; char dest2[1];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 0), strlcpy(dest2, src, 0), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[1], (st)-1\n");
        char src[] = "Hello World!"; char dest[1]; char dest2[1];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n", 
        ft_strlcpy(dest, src, (size_t)-1), strlcpy(dest2, src, (size_t)-1), dest, dest2);
    }

    {
        printf("Test: char src[] = \"Hello World!\"; char dest[1], (st)-2\n");
        char src[] = "Hello World!"; char dest[1]; char dest2[1];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n", 
        ft_strlcpy(dest, src, (size_t)-2), strlcpy(dest2, src, (size_t)-2), dest, dest2);
    }
   
    {
        printf("Test: char src[] = \"Hello World!\"; char dest[1], -2\n");
        char src[] = "Hello World!"; char dest[1]; char dest2[1];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n", 
        ft_strlcpy(dest, src, -2), strlcpy(dest2, src, -2), dest, dest2);
    }

    // Edge case: src is empty string, dest buffer size is 6, n is 6
    {
        printf("Test: char src[] = \"\"; char dest[6], 6\n");
        char src[] = ""; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 6), strlcpy(dest2, src, 6), dest, dest2);
    }

    // Edge case: dest buffer is NULL - should be segfault (what if src is null?)
    /*{
        printf("Test: char src[] = \"Hello World!\"; char *dest = NULL, 6\n");
        char src[] = "Hello World!"; char *dest = NULL; char *dest2 = NULL;
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 6), strlcpy(dest2, src, 6), dest, dest2);
        ft_strlcpy(dest, src, 6);
        strlcpy(dest, src, 6);
        printf("Result in both cases segfault - ok\n\n");
    }*/

    // Edge case: large n value, larger than the actual src length
    {
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 2147483647\n");
        char src[] = "Hello World!"; char dest[20]; char dest2[20];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 2147483647), strlcpy(dest2, src, 2147483647), dest, dest2);
    }

    // Edge case: dest buffer exactly fits src string + null terminator
    {
        printf("Test: char src[] = \"Hello\"; char dest[6], 6\n");
        char src[] = "Hello"; char dest[6]; char dest2[6];
        printf("Return value: %zu | %zu Result: \"%s\" | \"%s\"\n\n", 
        ft_strlcpy(dest, src, 6), strlcpy(dest2, src, 6), dest, dest2);
    }

    return 0;
}
