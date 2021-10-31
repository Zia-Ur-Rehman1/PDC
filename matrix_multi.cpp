#include <iostream>
#include <ctime>
#include <omp.h>
using namespace std;

int main()
{
    int matrix_Num = 400;
    int c[matrix_Num][matrix_Num];
    int a[matrix_Num][matrix_Num];
    int b[matrix_Num][matrix_Num];

    cout << "  \nThe matrix order N  = " << matrix_Num << "\n";
    int i, j, k;
    double wtime;
        
    wtime = omp_get_wtime();

    #pragma omp parallel shared(a, b, c, matrix_Num) private(i, j, k)   num_threads(8)
        {
        #pragma omp for
        for (i=0; i<matrix_Num;i++)
        {
            for (j=0;j<matrix_Num;j++)
            {
                a[i][j]=3;
                b[i][j]=a[i][j];
            }
        }

        #pragma omp for
        for (i = 0; i < matrix_Num; i++)
        {
            for (j = 0; j < matrix_Num; j++)
            {
                c[i][j] = 0.0;
                for (k = 0; k < matrix_Num; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
    }
    
    wtime = omp_get_wtime() - wtime;
    cout << "  Elapsed time in seconds = " << wtime << "\n";
    return 0;
}
