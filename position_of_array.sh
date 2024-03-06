#!/bin/bash

# Prompt user to enter the size of the array
echo "Enter the size of the array:"
read size

# Initialize an empty array
arr=()

# Prompt user to enter the elements of the array
echo "Enter the elements of the array:"
for ((i = 0; i < size; i++)); do
    echo "Enter element $((i + 1)): "
    read element
    arr+=("$element")
done

# Prompt user to enter the number to search for
echo "Enter the number to search for:"
read search_number

# Flag to track if the number is found
found=false

# Iterate through the array
for ((i = 0; i < ${#arr[@]}; i++)); do
    if [[ ${arr[$i]} -eq $search_number ]]; then
        found=true
        echo "The number $search_number is found at position $i"
    fi
done

# If the number is not found
if ! $found; then
    echo "The number $search_number is not found in the array."
fi
