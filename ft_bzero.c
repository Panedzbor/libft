/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:22:29 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/17 16:54:23 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"
/* #include "ft_memset.c" */

__attribute__((nonnull(1)))
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
