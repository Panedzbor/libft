#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "ft_calloc.c"

int main()
{
    {
        printf("Test 0: array of chars(0)\n");
        char *ptr; char *ptr2; size_t n = 0;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 1: array of chars(5)\n");
        char *ptr; char *ptr2; size_t n = 5;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 2: array of ints(5)\n");
        int *ptr; int *ptr2; size_t n = 5;
        ptr = (int *)ft_calloc(n, sizeof(int)); ptr2 = (int *)calloc(n, sizeof(int));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    /*{
        printf("Test 3: array of chars(SIZE_MAX)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }*/ //segfault
    printf("\n\n");
    {
        printf("Test 4: array of chars(SIZE_MAX + 1)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX + 1;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 4a: array of chars(SIZE_MAX + 2)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX + 2;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    /*{
        printf("Test 5: array of chars(SIZE_MAX - 1)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX - 1;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");*/ //segfault
    {
        printf("Test 6: array of ints(SIZE_MAX)\n");
        int *ptr; int *ptr2; size_t n = SIZE_MAX;
        ptr = (int *)ft_calloc(n, sizeof(int)); ptr2 = (int *)calloc(n, sizeof(int));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 7: array of ints(SIZE_MAX/3)\n");
        int *ptr; int *ptr2; size_t n = SIZE_MAX/3;
        ptr = (int *)ft_calloc(n, sizeof(int)); ptr2 = (int *)calloc(n, sizeof(int));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 7a: array of chars(SIZE_MAX/2)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX/2;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 7b: array of chars(SIZE_MAX/2+56)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX/2+56;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 7c: array of chars(SIZE_MAX/2-56)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX/2-56;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    /*{
        printf("Test 8: array of chars(SIZE_MAX/3)\n");
        char *ptr; char *ptr2; size_t n = SIZE_MAX/3;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");*/
    {
        printf("Test 9: array of chars(0)\n");
        char *ptr; char *ptr2; size_t n = 0;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 10: 0(0)\n");
        char *ptr; char *ptr2; size_t n = 0;
        ptr = (char *)ft_calloc(n, 0); ptr2 = (char *)calloc(n, 0);
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 11: 0(5)\n");
        char *ptr; char *ptr2; size_t n = 5;
        ptr = (char *)ft_calloc(n, 0); ptr2 = (char *)calloc(n, 0);
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 12: array of doubles(3)\n");
        double *ptr; double *ptr2; size_t n = 3;
        ptr = (double *)ft_calloc(n, sizeof(double)); ptr2 = (double *)calloc(n, sizeof(double));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%.1f ", ptr[a]); // Expect: 0.0 for all
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%.1f ", ptr2[a]); // Expect: 0.0 for all
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }
    printf("\n\n");
    {
        printf("Test 13: array of chars(-5)\n");
        char *ptr; char *ptr2; size_t n = -5;
        ptr = (char *)ft_calloc(n, sizeof(char)); ptr2 = (char *)calloc(n, sizeof(char));
        if (ptr != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr[a]);
        }
        else
            printf("null");
        printf(" | ");
        if (ptr2 != NULL)
        {
            for (size_t a = 0; a < n; a++)
                printf("%d", ptr2[a]);
        }
        else
            printf("null");
        free(ptr); free(ptr2);
    }

    

    return 0;
}