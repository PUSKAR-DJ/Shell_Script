
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
        result_matrix[$i,$j]=0
        for ((k=0; k<3; k++)); do
            result_matrix[$i,$j]=$(( ${result_matrix[$i,$j]} + ${matrix1[$i,$k]} * ${matrix2[$k,$j]} ))
        done
    done
done

echo "Result of matrix multiplication:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        echo -n "${result_matrix[$i,$j]} "
    done
    echo ""
done
