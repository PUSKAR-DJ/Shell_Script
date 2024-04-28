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

# Bubble sort
for ((i = 0; i < n-1; i++)); do
    for ((j = 0; j < n-i-1; j++)); do
        if (( ${array[j]} > ${array[j+1]} )); then
            # Swap elements if they are in the wrong order
            temp=${array[j]}
            array[j]=${array[j+1]}
            array[j+1]=$temp
        fi
    done
done

# Print the sorted array
echo "Sorted array:"
for ((i = 0; i < n; i++)); do
    echo -n "${array[i]} "
done
echo
