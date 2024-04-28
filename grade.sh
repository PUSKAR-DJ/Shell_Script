#Grade
#!/bin/bash

echo "Enter the marks: "
read marks

if [ $marks -ge 90 ] && [ $marks -le 100 ]; then
    grade="A+"
elif [ $marks -ge 80 ] && [ $marks -lt 90 ]; then
    grade="A"
elif [ $marks -ge 70 ] && [ $marks -lt 80 ]; then
    grade="B"
elif [ $marks -ge 60 ] && [ $marks -lt 70 ]; then
    grade="C"
elif [ $marks -ge 50 ] && [ $marks -lt 60 ]; then
    grade="D"
elif [ $marks -ge 0 ] && [ $marks -lt 50 ]; then
    grade="F"
else
    echo "Invalid marks entered."
    exit 1
fi

echo "Grade: $grade"
