#2.Write a Shell program to find the factorial of a number
echo "enter the number"
read n
i=1
fac=1
while [ $i -le $n ]
do
fac=$(expr $fac \* $i)
i=$(expr $i + 1)
done
echo "$fac"
