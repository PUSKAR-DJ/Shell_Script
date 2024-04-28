
declare -A matrix

echo "Enter values for the 3x3 matrix:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        read -p "Enter value for element ($i, $j): " value
        matrix[$i,$j]=$value
    done
done

echo "Displaying 3x3 matrix:"
for ((i=0; i<3; i++)); do
    for ((j=0; j<3; j++)); do
        echo -n "${matrix[$i,$j]} "
    done
    echo ""
done
