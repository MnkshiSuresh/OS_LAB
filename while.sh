i=1
echo "enter the limit"
read n
while [ $i -le $n ]
do
 echo "$i"
 i=$(expr $i + 1)
done
