#!/bin/bash
#Promt user for input
echo "Enter the first number."
read num1
echo "Enter the first number."
read num2

#Perform Addition
sum=$((num1+num2))
#Display the Result
echo "The sum of $num1 and $num2 is: $sum"
