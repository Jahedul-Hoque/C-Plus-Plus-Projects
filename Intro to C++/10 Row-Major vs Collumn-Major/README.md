
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



## 🔄 Cache Line Access and Movement
Here's how it works when accessing a cache line in detail:

### Initial Access (Cache Miss in L1):

Suppose the CPU needs to access matrix[0][0].

If this data is not in L1, the CPU checks if it's in L2.


### Eviction of Data:

L1 is full, so the CPU evicts the least recently used cache line to L2 (if L2 isn’t full).

If the data that was evicted from L1 is still needed soon, it might stay in L2.

L2 and L3 also follow the same eviction strategy: when they’re full, less frequently used data moves to the next cache level.


### Fetching from RAM:

If the CPU needs data from a cache line and that cache line isn't in L1, L2, or L3, it must fetch it from RAM (very slow).

RAM access latency is much higher than cache access, which is why efficient cache usage is so important for performance.



## 💡 Cache Hierarchy Recap
### L1 Cache: Smallest, fastest, and closest to the CPU cores.

Size: ~32 KB per core.

Latency: ~1-2 cycles.

Purpose: Stores frequently accessed data for fast processing.

### L2 Cache: Larger and slower than L1 but still fast.

Size: ~256 KB - 2 MB per core.

Latency: ~10-20 cycles.

Purpose: Stores data that doesn't fit in L1 but is still needed for future access.

### L3 Cache: Largest but slowest of the CPU caches (shared across cores).

Size: ~8-64 MB (depending on the processor).

Latency: ~30-40 cycles.

Purpose: Acts as a buffer between the cores and main RAM.


### RAM (Main Memory): Huge storage space but slow compared to caches.

Latency: ~100 ns (~100,000 cycles).
