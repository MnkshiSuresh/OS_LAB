echo "enter the no to find if its odd or even:"
read num
n=$(expr $num % 2)
if [ $n -eq 0 ]
then
echo "$num is even"
else
echo "$num is odd"
fi
