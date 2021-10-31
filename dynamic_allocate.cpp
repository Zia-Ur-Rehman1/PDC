#include <iostream>
#include <omp.h>

using namespace std;
// `M × M` matrix

// Dynamically allocate memory for 2D Array in C++
int main()
{
    // dynamically allocate memory of size `M × M`
    int M = 1024;
    
    int *A = new int[M * M];
    int *B = new int[M * M];
    int *C = new int[M * M];
    cout << "  \nThe matrix order   = " << M << "\n";
    int i, j, k;
    double wtime;
wtime = omp_get_wtime();
#pragma omp parallel shared(A, B, C, M) private(i, j, k)
    {
        // assign values to the allocated memory
        for (int i = 0; i < M; i++)
        {
#pragma omp for
            for (int j = 0; j < M; j++)
            {
                *(A + i * M + j) = 5;
                *(B + i * M + j) = 5;
            }
        }
#pragma omp for
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < M; j++)
            {
                *(C + i * M + j) = 0;

                for (k = 0; k < M; k++)
                {
                    *(C + i * M + j) = *(C + i * M + j) + *(A + i * M + j) * *(B + i * M + j);
                }
            }
        }
    }
    wtime = omp_get_wtime() - wtime;
    cout << "  Elapsed time in seconds = " << wtime << "\n";

    // deallocate memory
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}