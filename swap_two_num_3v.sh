#!/bin/bash
# Prompt user for input
echo "Enter the value of first variable: "
read var1
echo "Enter the value of second variable: "
read var2
# Display values before swapping
echo "Before swapping: var1=$var1, var2=$var2"
# Swap the values without using a third variable
var1=$((var1 + var2))
var2=$((var1 - var2))
var1=$((var1 - var2))# Display values after swapping
echo "After swapping: var1=$var1, var2=$var2"
