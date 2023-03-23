def collatz_sequence(n):
    seq = [n]
    while n != 1:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3*n + 1
        seq.append(n)
    return seq

start = 1

while True:
    seq = collatz_sequence(start)
    print(f"Sequence starting from {start}: {seq}")
    start += 1
