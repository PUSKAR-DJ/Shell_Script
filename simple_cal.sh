#!/bin/bash

echo "Simple Calculator"
echo "Enter two numbers: "
read num1
read num2

echo "Select operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice

case $choice in
    1)
        result=$(echo "$num1 + $num2" | bc)
        echo "Result: $result"
        ;;
    2)
        result=$(echo "$num1 - $num2" | bc)
        echo "Result: $result"
        ;;
    3)
        result=$(echo "$num1 * $num2" | bc)
        echo "Result: $result"
        ;;
    4)
        if [ $num2 -eq 0 ]; then
            echo "Error: Division by zero!"
        else
            result=$(echo "scale=2; $num1 / $num2" | bc)
            echo "Result: $result"
        fi
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
