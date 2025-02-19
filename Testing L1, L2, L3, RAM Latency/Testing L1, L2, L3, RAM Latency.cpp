#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Function to measure memory access time
double measure_latency(size_t vector_size) {
    vector<int> vec(vector_size, 1); // Allocate an vector of given size
    volatile int sum = 0; // Prevent compiler optimization

    auto start = chrono::high_resolution_clock::now();

    // starts the timer


    for (size_t i = 0; i < vector_size; i += 16) {
        sum += vec[i];
        // Access memory with a large stride to avoid prefetching
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    return elapsed.count();
    //stops timer and gives timer count
}

int main() {
    cout << "Cache & RAM Latency Test (Lower is Faster)\n";
    cout << "-------------------------------------------\n";

    size_t sizes[] = {

        8 * 1024,   // 8 KB  (Fits in L1)
        32 * 1024,  // 32 KB (L1 size)
        256 * 1024, // 256 KB (Fits in L2)
        2 * 1024 * 1024,  // 2 MB (Fits in L3)
        16 * 1024 * 1024, // 16 MB (Beyond L3, RAM access starts)
        128 * 1024 * 1024 // 128 MB (Definitely in RAM)
    };

    for (size_t size : sizes) {
        double time_taken = measure_latency(size / sizeof(int));
        // time taken is equal to 
        cout << "Vector Size: " << size / 1024 << " KB -> Time: " << time_taken << " seconds\n";
    }

    return 0;
}
