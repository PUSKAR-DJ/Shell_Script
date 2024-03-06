#!/bin/bash

# Prompt user for array size
echo "Enter the size of the array:"
read size

# Initialize an empty array
arr=()

# Prompt user for array elements and store them in the array
echo "Enter the elements of the array:"
for (( i = 0; i < size; i++ )); do
    echo "Enter element $((i + 1)): "
    read element
    arr+=("$element")
done

# Prompt user for target
echo "Enter the target number to search:"
read target

# Flag to track if target is found
found=false

# Loop through the array to search for the target
for (( i = 0; i < ${#arr[@]}; i++ )); do
    if [[ ${arr[$i]} -eq $target ]]; then
        echo "Target $target found at index $i"
        found=true
        break
    fi
done

# If target is not found
if ! $found; then
    echo "Target $target not found in the array"
fi
