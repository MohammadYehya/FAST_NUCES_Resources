echo "Enter five numbers"
read -p "Num1: " n[0]
read -p "Num2: " n[1]
read -p "Num3: " n[2]
read -p "Num4: " n[3]
read -p "Num5: " n[4]

max=-999999999999999999
min=999999999999999999

for i in ${n[@]}
do
	if [[ $i -gt max ]]
		then max=$i
	fi
	if [[ $i -lt min ]]
		then min=$i
	fi
done
echo "The largest number is $max"
echo "The smallest number is $min"
