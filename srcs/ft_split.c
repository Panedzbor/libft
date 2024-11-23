/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:00:01 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/23 20:15:01 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//PSEUDOCODE:
    //count delimiters
        //skip on beggining and end
        //skip delimiters next to each other
    //delimiters + 1 = amount of words
    //create space for array of pointers to text: (char **)malloc(amount of words * sizeof(char *))
    //create space for array of ints: (int *)malloc(amount of words * sizeof(int))
    //assign each word length to respective position in array
    //for each pointer to text create space for n chars (taken from ints array + 1)
    //copy words to respective memory slots
#include "libft.h"

size_t  count_delims(char *s, char c);
void    assign_ints(const char *s, char c, int  *iarr);
void    save_wlen(int *iarr, int *p, int *n);

char	**ft_split(const char *s, char c)
{
    size_t  delims;
    size_t  words;
    char    **array;
    int *iarr;

    delims = count_delims((char *)s, c);
    words = delims + 1;
    array = (char **)malloc(words * sizeof(char *));
    if (array == NULL)
        return (NULL);
    iarr = (int *)malloc(words * sizeof(int));
    if (iarr == NULL)
        return (NULL);
    assign_ints(s, c, iarr);

}

size_t  count_delims(char *s, char c)
{
    size_t  i;
    size_t  n;
    char    *trimmed;

    trimmed = ft_strtrim(s, (const char *)&c);
    i = 0;
    n = 0;
    while (trimmed[i] != '\0')
    {
        if (trimmed[i] == c && trimmed[i - 1] != c)
            n++;
        i++;
    }
    return (n);
}

void    assign_ints(const char *s, char c, int  *iarr)
{
    size_t  i;
    size_t  n;
    size_t  p;
    bool    flag;

    i = 0;
    n = 0;
    p = 0;
    while (s[i] != 0)
    {
        flag = false;
        while(s[i] != c)
        {
            n++;
            i++;
            flag = true;
        }
        if (flag = true)
            save_wlen(iarr, &p, &n);
        else
            i++;
    }
}

void    save_wlen(int *iarr, int *p, int *n)
{
    iarr[*p] = *n;
    (*p)++;
    *n = 0;
}
