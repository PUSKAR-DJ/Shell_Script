#!/bin/bash
# Prompt user for input
echo "Enter a number to find its factorial: "
read number
# Initialize result to 1
result=1
# Loop to calculate factorial
for ((i = 1; i <= number; i++)); do
result=$((result * i))
done
# Display the result
echo "The factorial of $number is: $result"
