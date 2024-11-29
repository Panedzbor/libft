#include <stdio.h>
#include <string.h>
#include "ft_strchr.c"
#include "ft_strrchr.c"

int main()
{
    char c = 'a';

    printf("abcd: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("abcd", c), strchr("abcd", c), ft_strrchr("abcd", c), strrchr("abcd", c));
    printf("bcd: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("bcd", c), strchr("bcd", c), ft_strrchr("bcd", c), strrchr("bcd", c));
    printf("bcda: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("bcda", c), strchr("bcda", c), ft_strrchr("bcda", c), strrchr("bcda", c));
    printf("a: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("a", c), strchr("a", c), ft_strrchr("a", c), strrchr("a", c));
    printf(": result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("", c), strchr("", c), ft_strrchr("", c), strrchr("", c));
    printf("abacd: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("abacd", c), strchr("abacd", c), ft_strrchr("abacd", c), strrchr("abacd", c));
    printf("abacda: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("abacda", c), strchr("abacda", c), ft_strrchr("abacda", c), strrchr("abacda", c));
    printf("zero sign: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("abacda", '\0'), strchr("abacda", '\0'), ft_strrchr("abacda", '\0'), strrchr("abacda", '\0'));
    printf("zero sign in empty: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("", '\0'), strchr("", '\0'), ft_strrchr("", '\0'), strrchr("", '\0'));
    printf("aaaaa: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("aaaaa", c), strchr("aaaaa", c), ft_strrchr("aaaaa", c), strrchr("aaaaa", c));
    printf("longer string of characters: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("longer string of characters", c), strchr("longer string of characters", c), ft_strrchr("longer string of characters", c), strrchr("longer string of characters", c));
    printf("longer string of characters: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("longer string of characters", c), strchr("longer string of characters", c), ft_strrchr("longer string of characters", c), strrchr("longer string of characters", c));
    printf("char overflow: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("char overflow", 't' + 256), strchr("char overflow", 't' + 256), ft_strrchr("char overflow", 't' + 256), strrchr("char overflow", 't' + 256));
    printf("char overflow: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr("char overflow", 't' + 258), strchr("char overflow", 't' + 258), ft_strrchr("char overflow", 't' + 258), strrchr("char overflow", 't' + 258));
    //printf("null: result \"%s\" | \"%s\" || \"%s\" | \"%s\"\n", ft_strchr(NULL, c), strchr(NULL, c), ft_strrchr(NULL, c), strrchr(NULL, c)); //should give null error


    return 0;
}
