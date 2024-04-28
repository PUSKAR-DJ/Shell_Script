#!/bin/bash

# Prompt user to enter the first number
echo "Enter the first number:"
read num1

# Prompt user to enter the operator
echo "Enter the operator (+, -, *, /):"
read operator

# Prompt user to enter the second number
echo "Enter the second number:"
read num2

# Perform arithmetic operation based on the operator
case $operator in
    "+")
        result=$((num1 + num2))
        ;;
    "-")
        result=$((num1 - num2))
        ;;
    "*")
        result=$((num1 * num2))
        ;;
    "/")
        if ((num2 != 0)); then
            result=$(awk "BEGIN {printf \"%.2f\", $num1 / $num2}")
        else
            echo "Error: Division by zero!"
            exit 1
        fi
        ;;
    *)
        echo "Error: Invalid operator!"
        exit 1
        ;;
esac

# Print the result
echo "Result: $result"
