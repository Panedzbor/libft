/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:45:52 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/26 14:23:12 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c" */

int		count_digits(unsigned int nb);
void	convert(char *number, unsigned int nb, int digits);

char	*ft_itoa(int n)
{
	unsigned int		nb;
	int					digits;
	char				*ptr;

	if (n < 0)
		nb = (-1) * n;
	else
		nb = n;
	digits = count_digits(nb);
	ptr = ft_calloc(digits + 1, sizeof(int));
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	convert(ptr, nb, digits);
	ptr[digits] = '\0';
	return (ptr);
}

int		count_digits(unsigned int nb)
{
	int	counter;

	counter = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

void	convert(char *number, unsigned int nb, int digits)
{
	int	r;
	int	i;

	r = nb % 10;
	i = nb / 10;
	number[digits - 1] = r + '0';
	digits--;
	while (i > 0)
	{
		nb = i;
		r = nb % 10;
		i = nb / 10;
		number[digits - 1] = r + '0';
		digits--;
	}
}

/* int main()
{
	ft_itoa(42);
	return 0;
} */