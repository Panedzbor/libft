/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat (1).c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:09:05 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/12 20:55:00 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
unsigned int	ft_strlcat2(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = 0;
	len_s = 0;
	i = 0;
	while (len_d < size && dest[len_d] != '\0')
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	if (size == 0)
		return (len_s);
	if (size <= len_d)
		return (size + len_s);
	while ((len_d + i < size) && src[i] != '\0')
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
/*int main()
{
	char dest[10] = "Hello";
	char src[10] = "World";
	unsigned int result = ft_strlcat(dest, src, 11);
	printf("String: %s\n", dest);
	printf("Return value: %u", result);
	return 0;
}*/
