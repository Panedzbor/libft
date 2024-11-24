/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:00:01 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/24 20:05:18 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PSEUDOCODE:
//    count delimiters
//        skip on beggining and end
//        skip delimiters next to each other
//    delimiters + 1 = amount of words
//    create space for array of pointers to text: 
//			(char **)malloc(amount of words * sizeof(char *))
//    create space for array of ints: 
//			(int *)malloc(amount of words * sizeof(int))
//    assign each word length to respective position in array
//    for each pointer to text create space (len = int array + 1)
//    free array of ints
//    copy words to respective memory slots
#include "libft.h"

size_t	count_delims(char *s, char c, bool *stop);
void	assign_ints(const char *s, char c, size_t *iarr);
char	**words_alloc(char **array, size_t *iarr, size_t words);
void	words_copy(const char *s, char c, char **array);

__attribute__((nonnull(1)))
char	**ft_split(const char *s, char c)
{
	size_t		delims;
	size_t		words;
	char		**array;
	size_t		*iarr;
	bool		stop;

	delims = count_delims((char *)s, c, &stop);
	if (stop == true)
		return (NULL);
	words = delims + 1;
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	iarr = (size_t *)malloc(words * sizeof(size_t));
	if (iarr == NULL)
		return (NULL);
	assign_ints(s, c, iarr);
	if (words_alloc(array, iarr, words) == NULL)
		return (NULL);
	words_copy(s, c, array);
	free(iarr);
	return (array);
}

size_t	count_delims(char *s, char c, bool *stop)
{
	size_t	i;
	size_t	n;
	char	*trimmed;

	*stop = false;
	trimmed = ft_strtrim(s, (const char *)&c);
	if (ft_strlen(trimmed) == 0)
	{
		*stop = true;
		return (0);
	}
	i = 0;
	n = 0;
	while (trimmed[i] != '\0')
	{
		if (trimmed[i] == c && trimmed[i - 1] != c)
			n++;
		i++;
	}
	free(trimmed);
	return (n);
}

void	assign_ints(const char *s, char c, size_t *iarr)
{
	size_t	i;
	size_t	n;
	size_t	p;
	bool	flag;

	i = 0;
	n = 0;
	p = 0;
	while (s[i] != '\0')
	{
		flag = false;
		while (s[i] != c && s[i] != '\0')
		{
			iarr[p] = ++n;
			i++;
			flag = true;
		}
		n = 0;
		if (flag == false)
			i++;
		else
			p++;
	}
}

char	**words_alloc(char **array, size_t *iarr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		array[i] = (char *)malloc((iarr[i] + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			while (i > 0)
			{
				free(array[i]);
				i--;
			}
			free(array[0]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

void	words_copy(const char *s, char c, char **array)
{
	size_t	i;
	size_t	p;
	size_t	l;

	i = 0;
	p = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[p][l++] = s[i];
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				array[p++][l] = '\0';
				l = 0;
			}
		}
		i++;
	}
}
