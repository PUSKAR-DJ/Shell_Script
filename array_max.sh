#!/bin/bash

# Prompt user to enter the number of elements
echo "Enter the number of elements in the array:"
read n

# Initialize an empty array
declare -a array

# Read elements from the user
echo "Enter the elements of the array:"
for ((i = 0; i < n; i++)); do
    read array[i]
done

# Initialize max as the first element of the array
max=${array[0]}

# Find maximum element
for ((i = 1; i < n; i++)); do
    if (( ${array[i]} > max )); then
        max=${array[i]}
    fi
done

# Print the maximum element
echo "Maximum element in the array: $max"
