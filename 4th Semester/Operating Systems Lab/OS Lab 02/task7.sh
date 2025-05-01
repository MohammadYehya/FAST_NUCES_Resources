read -p "Enter number: " num
res=1
for i in $(seq 1 $num)
do
	((res = res * i))
done
echo "The factorial is: $res"
