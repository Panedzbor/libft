#include <stdio.h>
#include <string.h>
#include "ft_strdup.c"

int main()
{
    {
        char *source = "abcd"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 1 (abcd): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = " "; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 2 ( ): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = ""; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 3 (\"\"): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "y"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 4 (y): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 5 (large string): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "    "; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 6 (    ): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "\n\n\n"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 7 (\"\\n\\n\\n\"): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "\0\0\0"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 7 (\"\\0\\0\\0\"): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "\0abc"; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 8 (\"\\nabc\"): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    /*{ 
        char *source = "\nabc"; char *result1 = ft_strdup(NULL); char *result2 = strdup(NULL);
        printf("Test 9 (null): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    } */ //null error
    {
        char *source = "This is a diverse $1ring     "; char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 10 (This is a diverse $1ring     ): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    {
        char *source = "こんにちは世界"; // "Hello, World" in Japanese
        char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 11 (Non-ASCII): \"%s\" | \"%s\"\n\n", result1, result2);
        free(result1); free(result2);
    }
    /* {
        size_t len = 1000000; // 1 million characters
        char *source = malloc(len + 1);
        memset(source, 'a', len);
        source[len] = '\0';
        char *result1 = ft_strdup(source); char *result2 = strdup(source);
        printf("Test 12 (Large string 1M): \"%s...\"\n\n", result1);
        free(result1); free(result2); free(source);
    } */


    return 0;
}

