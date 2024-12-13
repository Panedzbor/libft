#include <stdio.h>
#include <string.h>
#include "../libft/ft_memmove.c"

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main() {
    {
        char dest[10]; char dest2[10]; char src[10] = "Abcd";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 5), (char *)memmove(dest2, src, 5));
    }

    {
        char dest[10]; char dest2[10]; char src[10] = "Abcd";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 2), (char *)memmove(dest2, src, 2));
    }

    {
        char dest[3]; char dest2[3]; char src[10] = "Abcd";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 4), (char *)memmove(dest2, src, 4));
    }


    /*{ -will give error
        char dest[3]; char dest2[3]; char src[10] = "Abcd";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 5), (char *)memmove(dest2, src, 5));
    }*/

    {
        char dest[3]; char dest2[3]; char src[1] = "";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 1), (char *)memmove(dest2, src, 1));
    }

    /*{ -will give error
        char dest[3]; char dest2[3]; char src[1] = "";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 3), (char *)memmove(dest2, src, 3));
    }*/

    // Additional Tests

    // Zero-Length Copy
    {
        char dest[10] = "XXXXXXXXX"; char dest2[10] = "XXXXXXXXX"; char src[10] = "Abcd";

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 0), (char *)memmove(dest2, src, 0));
    }

    // Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!"; char src_dest2[20] = "HelloWorld!";
        
        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(src_dest1 + 2, src_dest1, 5), (char *)memmove(src_dest2 + 2, src_dest2, 5));
    }

    {
        char src_dest1[20] = "HelloWorld!"; char src_dest2[20] = "HelloWorld!";
        
        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(src_dest1 + 7, src_dest1, 5), (char *)memmove(src_dest2 + 7, src_dest2, 5));
    }

    {
        char src_dest1[20] = "HelloWorld!"; char src_dest2[20] = "HelloWorld!";
        
        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(src_dest1, src_dest1 + 4, 6), (char *)memmove(src_dest2, src_dest2 + 4, 6));
    }

    {
        char src_dest1[20] = "HelloWorld!"; char src_dest2[20] = "HelloWorld!";
        
        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(src_dest1, src_dest1, 6), (char *)memmove(src_dest2, src_dest2, 6));
    }

    /*{ //-should give a null error
        char src_dest1[20] = "HelloWorld!"; char src_dest2[20] = "HelloWorld!";
        
        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(NULL, NULL, 6), (char *)memmove(NULL, NULL, 6));
    }*/

    // Large Buffers
    {
        char src[1000]; char dest[1000]; char dest2[1000];

        for (int i = 0; i < 999; i++) 
        {
            src[i] = 'A' + (i % 26);
        }
        src[999] = '\0';

        printf("\"%s\" | \"%s\"\n", (char *)ft_memmove(dest, src, 1000), (char *)memmove(dest2, src, 1000));
    }

    return 0;
}
