#!/bin/bash
# Prompt user for input
echo "Enter the first number: "
read num1
echo "Enter the second number: "
read num2
echo "Enter the third number: "
read num3
# Initialize max to the first number
max=$num1
# Compare with the second number
if [ $num2 -gt $max ]; then
max=$num2
fi
# Compare with the third number
if [ $num3 -gt $max ]; then
max=$num3
fi
# Display the maximum number
echo "The maximum number among $num1, $num2, and $num3 is:$max"
