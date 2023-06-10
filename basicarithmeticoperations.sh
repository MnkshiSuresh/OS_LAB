echo "enter 2 numbers:"
read m n
sum=$(expr $m + $n)
dif=$(expr $m - $n)
pdt=$(expr $m \* $n)
div=$(expr $m / $n)
echo "sum is $sum"
echo "difference is $dif"
echo "product is $pdt"
echo "division is $div"
