
## 📜 Code Explanation
The `main.cpp` file contains two functions:

- **`rowMajorAccess(matrix)`**: Iterates through the matrix row by row.
- **`columnMajorAccess(matrix)`**: Iterates through the matrix column by column.
- Execution time is measured using `std::chrono`.

## ⚡ Performance Results
| **Access Pattern** | **Execution Time** |
|------------------|------------------|
| **Row-Major**    | ~19 seconds |
| **Column-Major** | ~60 seconds |

> **Observation:** Row-major access is **~4× faster** due to better CPU cache utilization.


## 🔍 How does the CPU execute data?

The CPU loads in 64 bytes of data to execute per cache line. Assume that is a 4x4 matrix of integers. 16 integers per cached line.
If the matrix data is stored in a Row-Major based fashion, it will be efficiently stored as the data will be all cached together continguous within memory allowing easy access by the CPU.
## 🔍 Why is Column-Major Slower?

✅ **Row-major** keeps data **contiguous in memory**, allowing cache lines (64 bytes) to hold multiple elements.  


![image](https://github.com/user-attachments/assets/e1fa870c-06db-4708-9d2b-b39cb8cd7bba)

### Memory Access pattern (Efficient):
[ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]


### Code:
```
for (int i = 0; i < SIZE; i++) {    // Iterate rows first
    for (int j = 0; j < SIZE; j++) { // Then columns
        matrix[i][j] += 1;
    }
}

```
![image](https://github.com/user-attachments/assets/ca634add-1863-4a46-bdc7-3a9288e0d7f8)


### Memory Access Pattern (Not Efficient):

[ 1, 4, 7, 2, 5, 8, 3, 6, 9 ]


### Code:
```
for (int j = 0; j < SIZE; j++) {    // Iterate columns first
    for (int i = 0; i < SIZE; i++) { // Then rows
        matrix[i][j] += 1;
    }
}
```



If the matrix data is stored in a Collumn-Major format, the data will be spread all over meaning the CPU may have to check L1 cache, L2 Cache and L3 cache and then the RAM which will take a lot longer.
❌ **Column-major** jumps across rows, leading to **cache misses** and slow RAM access.

