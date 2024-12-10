/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpylib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:28:38 by earutiun          #+#    #+#             */
/*   Updated: 2024/11/12 16:32:20 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t strlcpy_gpt(char *dest, const char *src, size_t size) {
    size_t src_len = 0;

    // Calculate the length of src
    while (src[src_len] != '\0') {
        src_len++;
    }

    // Only proceed if size is greater than 0
    if (size > 0) {
        size_t i;
        for (i = 0; i < size - 1 && src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';  // Ensure null-termination
    }

    // Return the length of src (similar to what strlcpy would return)
    return src_len;
}

