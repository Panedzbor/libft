/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:08 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/11 19:32:10 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__attribute__((nonnull(1, 2)))
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
/*#include <string.h>
int main()
{
        //char *s1 = "abcd";
        //char *s2 = "abcy";
        //size_t n = 5;
    printf("abcd - abcy (4): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 4), strncmp("abcd", "abcy", 4));
    printf("abcd - abcy (3): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 3), strncmp("abcd", "abcy", 3));
	printf("abcd - abcy (5): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 5), strncmp("abcd", "abcy", 5));
	printf("abcd - abcd (4): %d | %d\n", 
	ft_strncmp("abcd", "abcd", 4), strncmp("abcd", "abcd", 4));
	printf("a - a (1): %d | %d\n", 
	ft_strncmp("a", "a", 1), strncmp("a", "a", 1));
	printf("zex - rex (3): %d | %d\n", 
	ft_strncmp("zex", "rex", 3), strncmp("zex", "rex", 3));
	printf("tour - tourin (6): %d | %d\n", 
	ft_strncmp("tour", "tourin", 6), strncmp("tour", "tourin", 6));
	printf("tour - tourin (5): %d | %d\n", 
	ft_strncmp("tour", "tourin", 5), strncmp("tour", "tourin", 5));
	printf("a - a (0): %d | %d\n", 
	ft_strncmp("a", "a", 0), strncmp("a", "a", 0));
	printf("a - a (-1): %d | %d\n", 
	ft_strncmp("a", "a", -1), strncmp("a", "a", -1));
	printf(" - a (1): %d | %d\n", 
	ft_strncmp("", "a", 1), strncmp("", "a", 1));	
	printf("null null (1): %d | %d\n", 
	ft_strncmp(NULL, NULL, 1), strncmp(NULL, NULL, 1));	
        return 0;
}*/
