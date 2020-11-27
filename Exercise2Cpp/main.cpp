#include <iostream>
#include <omp.h>

using namespace std;

int count_partitions(int n, int m) {
    if (n <= 1 || m == 1) return 1;
    int count = 0;
    for (int k = std::min(n, m); k >= 1; --k) {
        #pragma omp task shared(count) if(n > 96 && m > 30)
        count += count_partitions(n - k, std::min(k, m));
    }
    #pragma omp taskwait
    return count;
}

int main() {
    auto start_time = omp_get_wtime();
// The right answer for 100 is 190569292
    #pragma omp parallel
    {
        #pragma omp single
        cout << count_partitions(100, 100) << endl;
    }
    auto calc_time = omp_get_wtime() - start_time;
    cout << "Calc time: " << calc_time << " sec.\n";
    return 0;
}



