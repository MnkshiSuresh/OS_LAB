#1.Write a Shell program to check the given year is leap year or not
echo "enter the year"
read year
y=$(expr $year % 4)
if [ $y -eq 0 ]
then
echo "$year leap year"
else
echo "$year not a leap year"
fi
