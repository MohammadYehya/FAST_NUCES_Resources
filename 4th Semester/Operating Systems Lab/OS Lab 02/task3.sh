read -p "Enter a number: " num

if [[ $num -lt 0 ]]
	then echo "The number is negative!"
	elif [[ $num -gt 0 ]]
		then echo "The number is positive!"
		elif [[ $num -eq 0 ]]
			then echo "The number is zero!"
			else echo "Invalid Entry!"
fi
