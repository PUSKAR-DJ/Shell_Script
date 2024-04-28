#!/bin/bash

# Prompt user to enter three numbers
echo "Enter three numbers separated by spaces:"
read num1 num2 num3

# Initialize max variable with the first number
max=$num1

# Compare max with the second number
if [ $num2 -gt $max ]; then
    max=$num2
fi

# Compare max with the third number
if [ $num3 -gt $max ]; then
    max=$num3
fi

# Print the maximum number
echo "The maximum of $num1, $num2, and $num3 is: $max"
