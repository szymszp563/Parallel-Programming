#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

int main() {

    int N = 1000000;
    int primeNumbers = 1;

    cout << "number of threads = " << omp_get_max_threads() << endl;

    auto start_time = omp_get_wtime();
//in case of my computer schedule(guided) was the fastest one
#pragma omp parallel for reduction(+:primeNumbers) schedule(guided)
    for(int i = 3; i <= N; i++) {
        bool prime = true;
        for(int j = 2; j <= ceil(sqrt(i)); j++) {
            if(i % j == 0) {
                prime = false;
                break;
            }
        }
        if(prime) {
            primeNumbers++;
        }
    }

    auto end_time = omp_get_wtime();

    cout << "For number N = " << N << " there are " << primeNumbers << " prime numbers\n";

    cout << "\nElapsed time: " << (end_time - start_time) << " sec.";

    return 0;
}


