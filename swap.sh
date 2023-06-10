#3.Write a Shell program to swap the two integers
echo "enter the 2 numbers to be swapped"
read one two
temp=$one
one=$two
two=$temp
echo "after swapping: $one $two"
