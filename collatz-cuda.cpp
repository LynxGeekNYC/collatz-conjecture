#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

__device__ int collatz_step(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

__global__ void collatz_sequence(int start, int length) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    int n = start + idx;
    int count = 1;

    while (n != 1) {
        n = collatz_step(n);
        count++;
    }

    printf("Sequence starting from %d: %d steps\n", start + idx, count);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s start [length]\n", argv[0]);
        exit(1);
    }

    int start = atoi(argv[1]);
    int length = 1;

    if (argc >= 3) {
        length = atoi(argv[2]);
    }

    int threads_per_block = 512;
    int blocks_per_grid = (length + threads_per_block - 1) / threads_per_block;

    collatz_sequence<<<blocks_per_grid, threads_per_block>>>(start, length);

    cudaDeviceSynchronize();

    return 0;
}
