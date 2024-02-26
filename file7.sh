#!/bin/bash
# Define a function to calculate factorial recursively
calculate_factorial() {
if [ $1 -eq 0 ]; then
echo 1
else
local sub_factorial
sub_factorial=$(calculate_factorial $(( $1 - 1 )))
echo $(( $1 * sub_factorial ))
fi
}
# Prompt user for input
echo "Enter a number to find its factorial: "
read number
# Call the function and display the result
result=$(calculate_factorial $number)
echo "The factorial of $number is: $result"
