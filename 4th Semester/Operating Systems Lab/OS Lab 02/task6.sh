read -p "Enter how many Fibonacci Numbers: " num
a=0
b=1
for i in $(seq 1 $num)
do
	echo "$a"
	c=$((a + b))
	a=$b
	b=$c
done
