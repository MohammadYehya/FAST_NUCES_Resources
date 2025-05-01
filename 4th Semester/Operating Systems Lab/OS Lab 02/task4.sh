read -p "Enter a number: " num
i=2
flag=0
while [[ $i -lt $num ]]
do
	if [[ $(( num % ((i++)) )) -eq 0 ]]
		then flag=1
		
	fi
done
if [[ $flag -eq 1 ]]
	then echo "Not a prime number!"
	else echo "Is a prime number!"
fi
