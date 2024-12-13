/* #include <string.h> */
#include "../libft/libft.h"

#include "../libft/ft_strlcpy.c"
#include "../libft/ft_strlcat.c"
#include "../libft/ft_bzero.c"



#include <bsd/string.h>

#include "../libft/libft.h"
/* # include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <setjmp.h>
# include <bsd/string.h> */

#include "../libft/ft_isprint.c"
#include "../libft/ft_toupper.c"
#include "../libft/ft_tolower.c"
#include "../libft/ft_strrchr.c"
#include "../libft/ft_strncmp.c"
#include "../libft/ft_strnstr.c"
#include "../libft/ft_memset.c"
#include "../libft/ft_putchar_fd.c"
#include "../libft/ft_putendl_fd.c"
#include "../libft/ft_putnbr_fd.c"
#include "../libft/ft_putstr_fd.c"
#include "../libft/ft_split.c"
#include "../libft/ft_strchr.c"
#include "../libft/ft_strdup.c"
#include "../libft/ft_striteri.c"
#include "../libft/ft_strjoin.c"
#include "../libft/ft_calloc.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_isalpha.c"
#include "../libft/ft_isdigit.c"
#include "../libft/ft_isalnum.c"
#include "../libft/ft_isascii.c"

#define RESET       "\033[0m"  // Reset to default color
#define RED         "\033[31m"
#define GREEN       "\033[32m"

int compare_results(const char* func_name, void *std_result, void *custom_result, int mode, int test, bool *pass, int datatype, size_t n) {
    /* int a = *(int*)std_result;
    int b = *(int*)custom_result; */
    
    if (mode == 1)
    {
        if (datatype == 1)
        {
            if (*(int *)std_result == *(int *)custom_result) {
                printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
                printf(GREEN "PASS");
                printf(RESET "\n");
            } else {
                printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
                printf(RED "FAIL\n" RESET);
                *pass = false;
                return 0;
            }
        }
        else if (datatype == 2)
        {
            if (std_result && custom_result)
            {
                if (strcmp((const char *)std_result, (const char *)custom_result) == 0)
                {
                    printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                    printf(GREEN "PASS");
                    printf(RESET "\n");
                }
                else
                {
                    printf("Test %d: %50s %15s || %-15s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                    *pass = false;
                    return 0;   
                }
            }
            else if (!(std_result && custom_result))
            {
                printf("Test %d: %50s %15s || %-15s - PASS\n", test, func_name, (char *)std_result, (char *)custom_result);
            }
            else{
                printf("Test %d: %50s %15s || %-15s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                *pass = false;   
                return 0;
            }
        }
        else if (datatype == 3)
        {
            if (std_result && custom_result)
            {
                if (memcmp((const void *)std_result, (const void *)custom_result, n) == 0)
                {
                    printf("Test %d: %50s   ", test, func_name);
                    fflush(stdout);
                    write(1, std_result, n);
                    write(1, " || ", 4);
                    write(1, custom_result, n);
                    printf(" - PASS\n");
                }
                else
                {
                    printf("Test %d: %50s %15s || %-15s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                    *pass = false;   
                    return 0;
                }
            }
            else if (!(std_result && custom_result))
            {
                printf("Test %d: %50s %15s || %-15s - PASS\n", test, func_name, (char *)std_result, (char *)custom_result);
            }
            else{
                printf("Test %d: %50s %15s || %-15s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                *pass = false;   
                return 0;
            }
        }
        else if(datatype == 4)
        {
            if(std_result == custom_result)
            {
                printf("Test %d: %50s %15p || %-15p - PASS\n", test, func_name, std_result, custom_result);
            }
            else
            {
                printf("Test %d: %50s %15p || %-15p - FAIL\n", test, func_name, std_result, custom_result);
                *pass = false;
                return 0;
            }
        }
    }
    else if (mode == 2)
    {
        if ((*(int *)std_result > 0 && *(int *)custom_result > 0) || (*(int *)std_result == 0 && *(int *)custom_result == 0) || (*(int *)std_result < 0 && *(int *)custom_result < 0)) {
        {
            printf("Test %d: %50s %15d || %-15d - PASS\n", test, func_name, *(int *)std_result, *(int *)custom_result);
        }
        } else {
            printf("Test %d: %50s %15d || %-15d - FAIL\n", test, func_name, *(int *)std_result, *(int *)custom_result);
            *pass = false;
            return 0;
        }
    }
    else if (mode == 3)
    {
        if (datatype == 1)
            printf("%14s %15d || %-15d - Not tested\n", func_name, *(int *)std_result, *(int *)custom_result);
        else if (datatype == 2)
            printf("%14s %15s || %-15s - Not tested\n", func_name, (char *)std_result, (char *)custom_result);
    }
    return 1;
}

struct tests
{
    char *function;
    bool passed;
};

void run_test_putnbr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_putnbr_fd...\n");

    int saved_stdout = dup(STDOUT_FILENO);

    // Test cases for putnbr_fd function comparison
    printf("expected result vs. ft_putnbr_fd:\n");

    // Test 1: Normal number
    {
        int i = 42;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(42)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2: Small positive number
    {
        int i = 4;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(4)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3: Small negative number
    {
        int i = -1;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4: Zero
    {
        int i = 0;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(0)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 5: Larger negative number
    {
        int i = -155;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-155)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 6: Large negative number
    {
        int i = -1234567;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-1234567)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 7: Maximum integer
    {
        int i = 2147483647;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(2147483647)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 8: Minimum integer
    {
        int i = -2147483648;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-2147483648)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 9: Character test (ASCII of 'a' is 97)
    {
        int i = 'a';
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd('a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_putnbr_fd...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}



int main() {
    bool grandpass = true;
    

    struct tests t[43] = {
        {"ft_isalpha", true},
        {"ft_isdigit", true},
        {"ft_isalnum", true},
        {"ft_isascii", true},
        {"ft_isprint", true},
        {"ft_toupper", true},
        {"ft_tolower", true},
        {"ft_strlen", true},
        {"ft_strchr", true},
        {"ft_strrchr", true},
        {"ft_strncmp", true},
        {"ft_strnstr", true},
        {"ft_strlcpy", true},
        {"ft_strlcat", true},
        {"ft_memset", true},
        {"ft_bzero", true},
        {"ft_memcpy", true},
        {"ft_memmove", true},
        {"ft_memchr", true},
        {"ft_memcmp", true},
        {"ft_atoi", true},
        {"ft_strdup", true},
        {"ft_calloc", true},
        {"ft_substr", true},
        {"ft_strjoin", true},
        {"ft_strtrim", true},
        {"ft_split", true},
        {"ft_itoa", true},
        {"ft_strmapi", true},
        {"ft_striteri", true},
        {"ft_putchar", true},
        {"ft_putstr", true},
        {"ft_putendl", true},
        {"ft_putnbr", true},
        {"ft_lstnew", true},
        {"ft_lstadd_front", true},
        {"ft_lstadd_back", true},
        {"ft_lstsize", true},
        {"ft_lstlast", true},
        {"ft_lstdelone", true},
        {"ft_lstclear", true},
        {"ft_lstiter", true},
        {"ft_lstmap", true}
    };
    int i = 0;
    run_test_putnbr(&grandpass, t, &i);
    

    return 0;
}


