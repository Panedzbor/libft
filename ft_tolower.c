/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:19:50 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/20 19:04:46 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	int	dif;

	dif = 'a' - 'A';
	if (ch >= 'A' && ch <= 'Z')
		return (ch + dif);
	return (ch);
}
