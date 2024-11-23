/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:48:27 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/23 19:13:36 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	define_start(char *new_str, const char *set, size_t set_size);
size_t	define_end(char *new_str, const char *set, size_t set_size);
void	trim_str(const char *s1, size_t start, size_t end, char *new_str);
bool	spec_cases(
			char **new_str, size_t set_size, size_t start, const char *s1);

__attribute__((nonnull(1, 2)))
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_str;
	size_t	set_size;
	size_t	start;
	size_t	end;
	bool	spec_case;

	new_str = (char *)s1;
	set_size = ft_strlen(set);
	start = define_start(new_str, set, set_size);
	spec_case = spec_cases(&new_str, set_size, start, s1);
	if (spec_case == false)
	{
		end = define_end(new_str, set, set_size);
		new_str = (char *)malloc((end - start + 2) * sizeof(char));
	}
	if (new_str == NULL)
		return (NULL);
	if (spec_case == false)
		trim_str(s1, start, end, new_str);
	return (new_str);
}

size_t	define_start(char *str, const char *set, size_t set_size)
{
	size_t	i;
	size_t	y;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (set[y] != '\0')
		{
			if (set[y] == str[i])
				break ;
			y++;
		}
		if (y != set_size)
			i++;
		else
			break ;
	}
	return ((size_t)(&str[i] - str));
}

size_t	define_end(char *str, const char *set, size_t set_size)
{
	size_t	i;
	size_t	y;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (&str[i] != str)
	{
		y = 0;
		while (set[y] != '\0')
		{
			if (set[y] == str[i])
				break ;
			y++;
		}
		if (y != set_size)
			i--;
		else
			break ;
	}
	return ((size_t)(&str[i] - str));
}

void	trim_str(const char *s1, size_t start, size_t end, char *new_str)
{
	size_t	i;

	i = 0;
	while (start <= end)
		new_str[i++] = (char)s1[start++];
	if (end > 0)
		new_str[i] = '\0';
}

bool	spec_cases(
		char **new_str, size_t set_size, size_t start, const char *s1)
{
	size_t	len;

	len = ft_strlen(s1);
	if (set_size == 0)
	{
		*new_str = ft_strdup(s1);
		return (true);
	}
	if (start == len)
	{
		*new_str = (char *)malloc(sizeof(char));
		if (*new_str == NULL)
			return (true);
		new_str[0][0] = '\0';
		return (true);
	}
	return (false);
}
