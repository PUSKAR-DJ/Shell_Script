#!/bin/bash
# Prompt user for input
echo "Enter the first number: "
read num1
echo "Enter the second number: "
read num2
# Perform addition
sum=$((num1 + num2))
# Display the result
echo "The sum of $num1 and $num2 is: $sum"
