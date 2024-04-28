

declare -A matrix1
declare -A matrix2
declare -A result_matrix

echo "Enter values for the first 3x3 matrix:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        read -p "Enter value for element ($i, $j): " value
        matrix1[$i,$j]=$value
    done
done

echo "Enter values for the second 3x3 matrix:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        read -p "Enter value for element ($i, $j): " value
        matrix2[$i,$j]=$value
    done
done

for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        result_matrix[$i,$j]=$(( ${matrix1[$i,$j]} + ${matrix2[$i,$j]} ))
    done
done

echo "Result of matrix addition:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        echo -n "${result_matrix[$i,$j]} "
    done
    echo ""
done
