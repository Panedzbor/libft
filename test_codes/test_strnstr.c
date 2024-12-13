#include <stdio.h>
#include <bsd/string.h>
#include "ft_strnstr.c"

int main()
{
    // Original test cases
    printf("Search \"romo\" in \"Voroboromoroko\" with size 0: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "romo", 0), strnstr("Voroboromoroko", "romo", 0));
    printf("Search \"romo\" in \"Voroboromoroko\" with size 9: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "romo", 9), strnstr("Voroboromoroko", "romo", 9));
    printf("Search \"romo\" in \"Voroboromoroko\" with size 14: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "romo", 14), strnstr("Voroboromoroko", "romo", 14));
    printf("Search \"romo\" in \"Voroboromoroko\" with size 15: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "romo", 15), strnstr("Voroboromoroko", "romo", 15));
    printf("Search \"romo\" in \"Voroboromoroko\" with size 20: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "romo", 20), strnstr("Voroboromoroko", "romo", 20));

    // Additional test cases
    printf("Search \"romo\" in \"\" with size 10: \"%s\" | \"%s\"\n", ft_strnstr("", "romo", 10), strnstr("", "romo", 10)); // Empty haystack
    printf("Search \"\" in \"Voroboromoroko\" with size 20: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "", 20), strnstr("Voroboromoroko", "", 20)); // Empty needle
    printf("Search \"\" in \"\" with size 0: \"%s\" | \"%s\"\n", ft_strnstr("", "", 0), strnstr("", "", 0)); // Both empty
    printf("Search \"x\" in \"Voroboromoroko\" with size 20: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "x", 20), strnstr("Voroboromoroko", "x", 20)); // Needle not in haystack
    printf("Search \"oko\" in \"Voroboromoroko\" with size 12: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "oko", 12), strnstr("Voroboromoroko", "oko", 12)); // Match at end within range
    printf("Search \"oko\" in \"Voroboromoroko\" with size 11: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "oko", 11), strnstr("Voroboromoroko", "oko", 11)); // Match at end out of range
    printf("Search \"oroboro\" in \"Voroboromoroko\" with size 10: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "oroboro", 10), strnstr("Voroboromoroko", "oroboro", 10)); // Partial match
    printf("Search \"Voroboromoroko\" in \"Voroboromoroko\" with size 20: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "Voroboromoroko", 20), strnstr("Voroboromoroko", "Voroboromoroko", 20)); // Full match
    printf("Search \"Voro\" in \"Voroboromoroko\" with size 3: \"%s\" | \"%s\"\n", ft_strnstr("Voroboromoroko", "Voro", 3), strnstr("Voroboromoroko", "Voro", 3)); // Partial prefix match
    printf("Search \"def\" in \"abcdef\" with size 6: \"%s\" | \"%s\"\n", ft_strnstr("abcdef", "def", 6), strnstr("abcdef", "def", 6)); // Match at end
    printf("Search \"def\" in \"abcdef\" with size 5: \"%s\" | \"%s\"\n", ft_strnstr("abcdef", "def", 5), strnstr("abcdef", "def", 5)); // Out of range
    printf("Search \"abc\" in \"abcdef\" with size 2: \"%s\" | \"%s\"\n", ft_strnstr("abcdef", "abc", 2), strnstr("abcdef", "abc", 2)); // Prefix out of range
    printf("Search \"a\" in \"a\" with size 1: \"%s\" | \"%s\"\n", ft_strnstr("a", "a", 1), strnstr("a", "a", 1)); // Single char match
    printf("Search \"b\" in \"a\" with size 1: \"%s\" | \"%s\"\n", ft_strnstr("a", "b", 1), strnstr("a", "b", 1)); // Single char no match
    printf("Search \"abc\" in \"abcabcabc\" with size 9: \"%s\" | \"%s\"\n", ft_strnstr("abcabcabc", "abc", 9), strnstr("abcabcabc", "abc", 9)); // Repeated pattern
    //printf("Search null in null with size 9: \"%s\" | \"%s\"\n", ft_strnstr(NULL, NULL, 9), strnstr(NULL, NULL, 9)); //segfault

    return 0;
}
