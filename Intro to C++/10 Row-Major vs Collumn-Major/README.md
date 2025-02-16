
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


### Matrix Representation:
  Col 0  Col 1  Col 2
+-----+-----+-----+
|  1  |  2  |  3  |  <- Access row 0 first
+-----+-----+-----+
|  4  |  5  |  6  |  <- Then row 1
+-----+-----+-----+
|  7  |  8  |  9  |  <- Then row 2
+-----+-----+-----+

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

### Matrix Representation:

  Col 0  Col 1  Col 2
+-----+-----+-----+
|  1  |  4  |  7  |  <- Access column 0 first
+-----+-----+-----+
|  2  |  5  |  8  |  <- Then column 1
+-----+-----+-----+
|  3  |  6  |  9  |  <- Then column 2
+-----+-----+-----+

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

