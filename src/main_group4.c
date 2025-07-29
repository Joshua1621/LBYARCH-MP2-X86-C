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
void saxpy_c_group4(int n, float A, float X[], float Y[], float Z[])
{
    int i;

    for (i = 0; i < n; i++)
    {
        Z[i] = A * X[i] + Y[i];
    }

}


int main()
{
    clock_t start, end;
    double c_time, asm_time;
    int sizes[] = { 1 << 20, 1 << 24, 1 << 28 };
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    float A = 2.0f;
    int correct, k, i, t, j, c;

    for (k = 0; k < num_sizes; k++) 
    {
        int n = sizes[k];

        // Allocate memory
        float* X = (float*)malloc(n * sizeof(float));
        float* Y = (float*)malloc(n * sizeof(float));
        float* Z_c = (float*)malloc(n * sizeof(float));
        float* Z_asm = (float*)malloc(n * sizeof(float));

        if (!X || !Y || !Z_c || !Z_asm) 
        {
            printf("Memory allocation failed for n = %d\n", n);
            exit(1);
        }


        // Initialize X and Y with random float values in [0, 100]
        for (i = 0; i < n; i++) 
        {
            X[i] = ((float)rand() / RAND_MAX) * 100.0f;
            Y[i] = ((float)rand() / RAND_MAX) * 100.0f;
        }


        // Time C version
        start = clock();

        for (t = 0; t < 30; t++) 
        {
            saxpy_c_group4(n, A, X, Y, Z_c);
        }

        end = clock();
        c_time = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("C version time for n = %d : %f seconds\n", n, c_time);
        printf("C version output for n = %d (first 10 elements):\n", n);

        for (j = 0; j < 10; j++) 
        {
            printf("%f ", Z_c[j]);
        }

        printf("\n\n");


        // Time Assembly version
        start = clock();

        for (t = 0; t < 30; t++) 
        {
            saxpy_asm_group4(A, X, Y, Z_asm, n);
        }

        end = clock();
        asm_time = ((double)(end - start)) / CLOCKS_PER_SEC / 30.0;

        printf("Assembly version time for n = %d : %f seconds\n", n, asm_time);
        printf("Assembly version output for n = %d (first 10 elements):\n", n);

        for (int j = 0; j < 10; j++) 
        {
            printf("%f ", Z_asm[j]);
        }

        printf("\n\n");


        // Check correctness
        correct = 1;
        for (c = 0; c < n; c++) 
        {
            if (fabsf(Z_c[c] - Z_asm[c]) > 1e-5f) 
            {
                correct = 0;
                printf("Mismatch at index %d: C = %f, ASM = %f\n\n", c, Z_c[c], Z_asm[c]);
                break;
            }
        }

        if (correct) 
        {
            printf("Correctness check passed (C vs ASM)\n\n");
        }
        else 
        {
            printf("Correctness check failed (C vs ASM)\n");
        }

        printf("\n--------------------------------------------------------\n\n");

        // Free memory
        free(X);
        free(Y);
        free(Z_c);
        free(Z_asm);
    }

    return 0;
}
