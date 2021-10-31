#include <iostream>
#include <omp.h>
#include <ctime>

using namespace std;
int main()
{
    long double f = 1;

    int num;
    double wtime;

    printf("Input the number : ");
    cin >> num;
    wtime = omp_get_wtime();
// #pragma omp parallel reduction(* \
//                                : f)
    {
#pragma omp parallel for reduction(*:f)
        for (int i = 1; i <= num; i++)
        {
            f = f * i;
        }
        printf("%d\n", omp_get_thread_num());
    }
    wtime = omp_get_wtime() - wtime;
    cout << "  Elapsed seconds = " << wtime << "\n";
    cout << "Threads Ends" << endl;
    cout << "The Factorial of " << num << " is " << f << endl;

    return 0;
}
