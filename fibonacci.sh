#!/bin/bash

# Prompt user to enter the number of terms
echo "Enter the number of terms in the Fibonacci sequence:"
read n

# Check if the input is valid
if ((n <= 0)); then
    echo "Error: Please enter a positive integer greater than 0."
    exit 1
fi

# Fibonacci sequence generation
# Initialize the first two terms
fibonacci=(0 1)

# Generate the sequence
for ((i = 2; i < n; i++)); do
    next_term=$((fibonacci[i-1] + fibonacci[i-2]))
    fibonacci+=($next_term)
done

# Print the Fibonacci sequence
echo "Fibonacci sequence up to the $n-th term:"
for ((i = 0; i < n; i++)); do
    echo -n "${fibonacci[i]} "
done
echo
