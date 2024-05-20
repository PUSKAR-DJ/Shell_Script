#!/bin/bash

#Sum Of Digits
#Enter the size of the elements
echo "Enter Size(N)"
read N

sum=0
echo "Enter Numbers"
for((i=1;i<=N;i++))
do
  read num         
  sum=$((sum + num)) 
done

echo Sum of Digits = $sum