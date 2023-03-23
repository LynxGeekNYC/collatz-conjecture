# collatz-conjecture
This script will probably break my computer lol If you know what the collatz conjecture is, God bless you! lol

# What is the Collatz Conjecture (3n+1)?
The Collatz Conjecture, also known as the 3n + 1 conjecture or the hailstone sequence, is a famous unsolved problem in mathematics.

The conjecture is as follows: Start with any positive integer. If it's even, divide it by 2. If it's odd, multiply it by 3 and add 1. Repeat this process with the resulting number, and keep going. The conjecture states that no matter what number you start with, you will eventually reach the number 1.

The pattern that emerges from applying the Collatz Conjecture to a given number is a sequence of numbers that can be represented as follows:

Starting number → (1st iteration) → (2nd iteration) → ... → (n-th iteration) → 1

For example, starting with the number 6, we get the following sequence:

6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1

The Collatz Conjecture states that this sequence will eventually reach 1, no matter what number you start with. However, despite its simplicity, the Collatz Conjecture remains unsolved, and it is not known whether there exists a number for which the sequence does not reach 1.

As of now, no one has been able to find a number for which the Collatz sequence does not eventually reach 1, even though this conjecture has been extensively tested using computer programs. Therefore, it is highly unlikely that you will be able to find a number for which the Collatz sequence does not reach 1 using a Python script or any other computational method. Nonetheless, Here is a simple Python script that generates the Collatz sequence for a given starting number (1) and continues until it reaches 1. The script will keep generating sequences for larger and larger starting numbers until it is stopped manually.

This script defines the collatz_sequence function that generates the Collatz sequence for a given starting number, as before. It then sets the initial starting number to 1 and enters an infinite loop. In each iteration of the loop, it generates the Collatz sequence for the current starting number, prints the sequence to the console, and increments the starting number by 1. This process continues indefinitely until the script is stopped manually.

Note that this modified script will generate the Collatz sequence for an infinite number of starting numbers, but it is extremely unlikely to find a sequence that does not eventually reach 1.

# Variations of the scripts
I made two separate scripts. One is standard CPU and one is for GPU. 

# Warning
I had no time to test run it for a long time so I have no idea what it will do with overheating the GPU. 
