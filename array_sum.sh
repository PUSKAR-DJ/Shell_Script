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

# Initialize sum
sum=0

# Calculate sum of array elements
for ((i = 0; i < n; i++)); do
    (( sum += ${array[i]} ))
done

# Print the sum
echo "Sum of array elements: $sum"
