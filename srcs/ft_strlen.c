/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:21:35 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/11 18:58:21 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__attribute__((nonnull))
size_t	ft_strlen(const char *str)
{
	size_t	chars;

	chars = 0;
	while (str[chars] != '\0')
		chars++;
	return (chars);
}
/*int main(void)
{
	//char *str = "Text";
	printf("Text: %zu | %zu\n", ft_strlen("Text"), strlen("Text"));
	printf(": %zu | %zu\n", ft_strlen(""), strlen(""));
	printf("\\0: %zu | %zu\n", ft_strlen("\0"), strlen("\0"));
	printf("null: %zu | %zu\n", ft_strlen(NULL), strlen(NULL));

	return 0;
}*/
