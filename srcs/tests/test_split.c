#include "libft.h"
#include "ft_split.c"

int main()
{
    int c = 0;
    c++;
    {
        const char *s = "   abc def gh i jk"; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc def gh i jk"; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc def gh i jk   "; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "   abc def gh i jk   "; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "   abc   def gh      i jk   "; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc:def: ghi:jk:l"; char ch = ':'; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc:def:ghi:jk:l"; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc\ndef\nghi"; char ch = '\n'; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "abc\0def\0ghi"; char ch = '\0'; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"abc\\0def\\0ghi)\"/\"\\0\"):\n", c);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "     "; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "a"; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = " "; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = ""; char ch = ' '; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = ""; char ch = '\0'; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    c++;
    {
        const char *s = "a"; char ch = '\0'; int i;
        char **ar = ft_split(s, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    }
    /* c++; //null error
    {
        const char *s = "null"; char ch = ' '; int i;
        char **ar = ft_split(NULL, ch);
        if (ar != NULL)
        {
            printf("Test %d (\"%s\"/\"%c\"):\n", c, s, ch);
            for (i = 0; ar[i] != NULL; i++)
                printf("%s\n", ar[i]);
            printf("\n");
            for (i = 0; ar[i] != NULL; i++) free(ar[i]);
            free(ar[i]); free(ar);
        }
        else
            printf("Test %d (\"%s\"/\"%c\"): (null)\n\n", c, s, ch);
    } */
    return 0;
}