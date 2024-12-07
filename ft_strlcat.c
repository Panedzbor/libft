/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:09:05 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/12 21:26:44 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_count(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;
	size_t	src_size;

	j = 0;
	src_size = size_count(src);
	dest_size = size_count(dest);
	i = dest_size;
	if (size == 0)
		return (src_size);
	if (size <= dest_size)
		return (size + src_size);
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_size + src_size);
}

static int	size_count(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*#include "ft_strlcat (1).c"
int main()
{
	char dest[5] = "Hello";
	char src[10] = "World";
	unsigned int result = ft_strlcat(dest, src, 3);
	printf("String: %s\n", dest);
	printf("Return value: %u\n\n", result);
	char dest2[5] = "Hello";
	result = ft_strlcat2(dest2, src, 3);
	printf("String: %s\n", dest2);
        printf("Return value: %u\n", result);
	return 0;
}*/

/* #include <stdio.h>
#include <string.h>

int main() {
    char dest[50] = "rrrrrrrrrrrrrrr";
    char src[] = "";
    size_t size = 31;

    size_t result = ft_strlcat(dest, src, size);
    printf("Result: %zu\n", result);            // Expected: 31
    printf("Concatenated String: %s\n", dest);  // Expected: "rrrrrrrrrrrrrrr"

    return 0;
} */

