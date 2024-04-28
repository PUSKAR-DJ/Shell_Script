#!/bin/bash

gcd() {
    local a=$1
    local b=$2
    while [[ $b -ne 0 ]]; do
        local temp=$b
        b=$((a % b))
        a=$temp
    done
    echo $a
}

echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2

result=$(gcd $num1 $num2)
echo "GCD of $num1 and $num2 is: $result"
