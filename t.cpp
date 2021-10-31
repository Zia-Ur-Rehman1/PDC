#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

int main();
int main()

{
    int NUM = 500;
    double a[NUM][NUM], b[NUM][NUM], c[NUM][NUM];
    int i, j, k;
    int thread_num;
    double wtime;
    cout << "Hello";

    thread_num = omp_get_max_threads();
    cout << "  The matrix order N = " << NUM << "\n";
    wtime = omp_get_wtime();

#pragma omp parallel shared(a, b, c, NUM) private(i, j, k) num_threads(18)
    {
#pragma omp for
        for (i = 0; i < NUM; i++)
        {
            for (j = 0; j < NUM; j++)
            {

                a[i][j] = 1;
            }
        }

#pragma omp for
        for (i = 0; i < NUM; i++)
        {
            for (j = 0; j < NUM; j++)
            {
                b[i][j] = a[i][j];
            }
        }

#pragma omp for
        for (i = 0; i < NUM; i++)
        {
            for (j = 0; j < NUM; j++)
            {
                c[i][j] = 0.0;
                for (k = 0; k < NUM; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
    }
    wtime = omp_get_wtime() - wtime;
    cout << "Hello";
    cout << "  Elapsed seconds = " << wtime << "\n";
    cout << "  C(" << NUM << "," << NUM << ")"
         << "  = " << c[94][99] << "\n";
    return 0;
}
