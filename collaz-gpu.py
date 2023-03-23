import numba
import numpy as np

@numba.jit(nopython=True, parallel=True)
def collatz_sequence(n):
    seq = np.zeros(1000000, np.int64)
    i = 0
    while n != 1:
        seq[i] = n
        i += 1
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3*n + 1
    seq[i] = 1
    return seq[:i+1]

start = 1

while True:
    seq = collatz_sequence(start)
    print(f"Sequence starting from {start}: {seq}")
    start += 1
