#include <iostream>
#include <vector>
#include <chrono>

using namespace std;  // Use standard namespace

const int SIZE = 50000; // Define matrix size (1000x1000)

// Function for row-major access (efficient)
void rowMajorAccess(vector<vector<int>>& matrix) {
    auto start = chrono::high_resolution_clock::now();  // Start time measurement

    // Iterate over rows first, then columns (row-major order)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] += 1;  // Access elements in row order
        }
    }

    auto end = chrono::high_resolution_clock::now();  // End time measurement
    chrono::duration<double> elapsed = end - start;  // Compute elapsed time
    cout << "Row-major access time: " << elapsed.count() << " seconds\n";  // Print execution time
}

// Function for column-major access (inefficient)
void columnMajorAccess(vector<vector<int>>& matrix) {
    auto start = chrono::high_resolution_clock::now();  // Start time measurement

    // Iterate over columns first, then rows (column-major order)
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            matrix[i][j] += 1;  // Adding 1 to each element in the 2d vector
        }
    }

    auto end = chrono::high_resolution_clock::now();  // End time measurement
    chrono::duration<double> elapsed = end - start;  // Compute elapsed time
    cout << "Column-major access time: " << elapsed.count() << " seconds\n";  // Print execution time
}

int main() {
    // Initialize a 1000x1000 matrix filled with zeros
    vector<vector<int>> matrix(SIZE, vector<int>(SIZE, 0));

    cout << "Testing cache efficiency:\n";

    rowMajorAccess(matrix);   // Measure row-major access time
    columnMajorAccess(matrix); // Measure column-major access time

    return 0;
}
