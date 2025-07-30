/*
 * Group 4 Members: Joshua Benedict B. Co & Llandro Massimo B. Colcol
 * Course & Section: LBYARCH | S12A
 *
 * C function implementation of SAXPY (Single-Precision A*X Plus Y)
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// This is an assembly function declaration for the SAXPY operation
extern void saxpy_asm_group4(float A, float* X, float* Y, float* Z, int n);


// This function is a C implementation of the SAXPY operation
void saxpy_c_group4(float A, float* X, float* Y, float* Z, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        Z[i] = A * X[i] + Y[i];
    }
}


int main()
{
    // Sir Rog's way
    int sizes[] = { 1 << 20, 1 << 24, 1 << 28 };
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    float A = 2.0f, diff;

    int k, n, i;
    clock_t start, end;
    double time_c, time_asm, speedup;
    int correct;

    printf("Implementation of SAXPY (Single-Precision A * X + Y) function in Assembly and C (Performance Analysis)\n");
    printf("Group 4 Members: Joshua Benedict B. Co & Llandro Massimo B. Colcol\n\n");

    for (k = 0; k < num_sizes; k++)
    {
        n = sizes[k];

        printf("Testing with n = %d\n", n);

        // Allocate memory
        float* X = (float*)malloc(n * sizeof(float));
        float* Y = (float*)malloc(n * sizeof(float));
        float* Z_c = (float*)malloc(n * sizeof(float));
        float* Z_asm = (float*)malloc(n * sizeof(float));

        // Check if memory allocation was successful
        if (!X || !Y || !Z_c || !Z_asm)
        {
            printf("Memory allocation failed for n = %d\n", n);
            printf("Try reducing vector size or use a machine with more RAM\n\n");
            continue;
        }

        // Initialize X and Y with random float values in [0, 100]
        for (i = 0; i < n; i++)
        {
            X[i] = ((float)rand() / RAND_MAX) * 100.0f;
            Y[i] = ((float)rand() / RAND_MAX) * 100.0f;
        }

        // Time C version
        start = clock();

        for (i = 0; i < 30; i++)
        {
            saxpy_c_group4(A, X, Y, Z_c, n);
        }

        end = clock();
        time_c = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("C version time for n = %d : %f seconds\n", n, time_c);
        printf("C version output for n = %d (first 10 elements):\n", n);

        for (i = 0; i < 10; i++)
        {
            printf("%f ", Z_c[i]);
        }

        printf("\n\n");

        // Time Assembly version
        start = clock();

        for (i = 0; i < 30; i++)
        {
            saxpy_asm_group4(A, X, Y, Z_asm, n);
        }

        end = clock();
        time_asm = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("Assembly version time for n = %d : %f seconds\n", n, time_asm);
        printf("Assembly version output for n = %d (first 10 elements):\n", n);

        for (i = 0; i < 10; i++)
        {
            printf("%f ", Z_asm[i]);
        }

        printf("\n\n");

        // Correctness check
        correct = 1;

        for (i = 0; i < n; i++)
        {
            diff = fabsf(Z_c[i] - Z_asm[i]);

            if (diff > 1e-6f)
            {
                correct = 0;
                printf("Mismatch at index %d: C = %f, ASM = %f, Diff = %f\n", i, Z_c[i], Z_asm[i], diff);
            }
        }

        if (correct)
        {
            printf("Correctness check: PASSED\n\n");
        }
        else
        {
            printf("Correctness check: FAILED\n\n");
        }

        printf("--------------------------------------------------------\n\n");

        // Free memory
        free(X);
        free(Y);
        free(Z_c);
        free(Z_asm);
    }

    return 0;
}