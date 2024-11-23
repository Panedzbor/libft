#include <stdio.h>
#include <string.h> // For the standard bzero
#include <stdbool.h>
#include "ft_bzero.c" // Include your implementation

void printArray(int arr[], float arr1[], int n, int d)
{
   
   if (d == 1)
   {
    for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
   }

   if (d == 2)
   {
    for (int i=0; i<n; i++)
      printf("%f ", arr1[i]);
   }
}

int main()
{
    {
        printf("Test 1:");
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(str1 + 13, 8*sizeof(char));
        bzero(str2 + 13, 8*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }

    {
        printf("Test 2:");
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(str1 + 35, 8*sizeof(char));
        bzero(str2 + 35, 8*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }

    {
        printf("Test 3:");
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(str1, 8*sizeof(char));
        bzero(str2, 8*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }

    {
        printf("Test 4:");
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(str1, 0*sizeof(char));
        bzero(str2, 0*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }

    /*{
        printf("Test 5:");
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore bzero(): \"%s\"\n", str1);

        ft_bzero(str1+50, 8*sizeof(char));
        bzero(str2+50, 8*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }*/
    
    {
        printf("Test 6:");
        

        int n = 10;
        int arr[n];
        int arr2[n];

        printf("\nArrays before bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
        // Fill whole array with 0.
        ft_bzero(arr, n*sizeof(arr[0]));
        bzero(arr2, n*sizeof(arr[0]));
        printf("\nArrays after bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
    }

    {
        printf("\n\nTest 7:");
        

        int n = 10;
        int arr[n];
        int arr2[n];

        printf("\nArrays before bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
        // Fill whole array with 0.
        ft_bzero(arr, n*sizeof(arr[0]));
        bzero(arr2, n*sizeof(arr[0]));
        printf("\nArrays after bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
    }

    {
        printf("\n\nTest 8:");
        

        int n = 5;
        float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

        printf("\nArrays before bzero()\n");
        printArray(NULL, arr, n, 2);
        printf("\n");
        printArray(NULL, arr2, n, 2);
        // Fill whole array with 0.
        ft_bzero(arr, n*sizeof(arr[0]));
        bzero(arr2, n*sizeof(arr[0]));
        printf("\nArrays after bzero()\n");
        printArray(NULL, arr, n, 2);
        printf("\n");
        printArray(NULL, arr2, n, 2);
    }

    /*{
        printf("\n\nTest 9:");
        

        int n = 0;
        int arr[0];
        int arr2[0];

        printf("\nArrays before bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
        // Fill whole array with 0.
        ft_bzero(arr, n*sizeof(arr[0]));
        bzero(arr2, n*sizeof(arr[0]));
        printf("\nArrays after bzero()\n");
        printArray(arr, NULL, n, 1);
        printf("\n");
        printArray(arr2, NULL, n, 1);
    }*/

    {
        printf("\n\nTest 10:");
        char str1[50];
        char str2[50];
        printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(str1, 8*sizeof(char));
        bzero(str2, 8*sizeof(char));

        printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }

    /*{ //-should give null error
        printf("\n\nTest 11:");
        //char str1[50];
        //char str2[50];
        //printf("\nBefore bzero(): \"%s\"\n", str1);

        // Fill 8 characters starting from str[13] with '.'
        ft_bzero(NULL, 8*sizeof(char));
        bzero(NULL, 8*sizeof(char));

        //printf("After bzero():  \"%s\" | \"%s\"\n\n", str1, str2);
    }*/
    
    return 0;
}