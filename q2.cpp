#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

int main();
int main()

{
    int NUM = 4;
    //double a[NUM][NUM], b[NUM][NUM], c[NUM][NUM];
    int c[4][4];
    int i, j, k;
    int thread_num;
    double wtime;
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}};

    int b[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}};

    thread_num = omp_get_max_threads();
    cout << "  The matrix order N                 = " << NUM << "\n";
    wtime = omp_get_wtime();

#pragma omp parallel shared(a, b, c, NUM) private(i, j, k)
    {

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
    cout << "  Elapsed seconds = " << wtime << "\n";
    cout << "  C(" << NUM << "," << NUM << ")"
         << "  = " << c[94][99] << "\n";
    return 0;
}
