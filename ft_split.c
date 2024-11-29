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
//    create space for array of ints: 
//    assign each word length to respective position in array
//    for each pointer to text create space (len = int array + 1)
//    free array of ints
//    copy words to respective memory slots
#include "libft.h"

static size_t	count_words(char *s, char c/* , char *set */, bool *no_words);
static void	assign_ints(const char *s, char c, size_t *iarr);
static char	**words_alloc(char **array, size_t *iarr, size_t words);
static void	words_copy(const char *s, char c, char **array);

typedef struct variable_storage
{
	/* size_t		delims; */
	size_t		words;
	char		**array;
	size_t		*iarr;
	char		set[2];
	bool		no_words;
}t_vs;

__attribute__((nonnull(1)))
char	**ft_split(const char *s, char c)
{
	t_vs	vs;

	vs.set[0] = c;
	vs.set[1] = '\0';
	vs.words = count_words((char *)s, c,/*  vs.set, */ &vs.no_words);
	/* vs.words = vs.delims + 1; */
	vs.array = (char **)ft_calloc(vs.words + 1/*  - (size_t)vs.no_words */, sizeof(char *));
	if (vs.array == NULL)
		return (NULL);
	vs.array[vs.words/*  - (size_t)vs.no_words */] = NULL;
	if (vs.no_words == true)
		return (vs.array);
	vs.iarr = (size_t *)ft_calloc(vs.words, sizeof(size_t));
	if (vs.iarr == NULL)
	{
		free (vs.array);
		return (NULL);
	}
	assign_ints(s, c, vs.iarr);
	if (words_alloc(vs.array, vs.iarr, vs.words) == NULL)
		return (NULL);
	words_copy(s, c, vs.array);
	free(vs.iarr);
	return (vs.array);
}

static size_t	count_words(char *s, char c/* , char *set */, bool *no_words)
{
	size_t	i;
	size_t	n;
	bool	flag;
	/* char	*trimmed; */

	flag = false;
	*no_words = false;
	/* trimmed = ft_strtrim((const char *)s, (const char *)set);
	if (trimmed == NULL)
		return (0); */
	//if (ft_strlen(s) == 0)
	//{
		/* free (trimmed); */
	/* 	*no_words = true;
		return (0);
	} */
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		/* if (s[i] == c && s[i - 1] != c) */
		if (s[i] != c)
		{
			if (flag == false)
			{
				n++;
				flag = true;
			}
		}
		else
			flag = false;
		i++;
	}
	/* free(trimmed); */
	return (n);
}

static void	assign_ints(const char *s, char c, size_t *iarr)
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

static char	**words_alloc(char **array, size_t *iarr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		array[i] = (char *)ft_calloc(iarr[i] + 1, sizeof(char));
		if (array[i] == NULL)
		{
			while (i > 0)
			{
				free(array[i]);
				i--;
			}
			free(array[0]);
			free(array);
			free(iarr);
			return (NULL);
		}
		i++;
	}
	return (array);
}

static void	words_copy(const char *s, char c, char **array)
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
