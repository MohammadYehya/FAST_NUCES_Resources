echo "K213309_Mohammad Yehya_OSLab02"
echo $BASH
echo $BASH_VERSION
echo $PWD
echo $HOME

x=3309
y=3.99
message="What is your name?"

echo $x
echo $y
echo $message

read num
echo "Your name is $num"
#echo this is a comment
echo $0
echo "Argument#1: "$1
echo "Argument#2: "$2
echo "Argument#3: "$3

read -p "This is a same line prompt " x
read -sp"This is a secure prompt " x

read -p "Enter the first number: " n1
read -p "Enter the second number: " n2
if [[ $n1 -lt $n2 ]];
	then echo "$n1 is smaller than $n2"
	elif [[ $n2 -lt $n1 ]]; 
		then echo "$n2 is smaller than $n1"
		else echo "Both are the same number"
fi
#((result = $n1 + $n2))
echo "The sum of the two numbers is: " $(( $n1 + $n2 ))

read -p "Enter num1: " n1
read -p "Enter num2: " n2
read -p "Enter num3: " n3
if [[ $n1 -gt $n2 && $n1 -gt $n3 ]];
	then echo "$n1 is the greatest number"
	elif [[ $n2 -gt $n1 && $n2 -gt $n3 ]];
		then echo "$n2 is the greatest number"
		else echo "$n3 is the greatest number"
fi
read -p "Do you like OS Labs?(Y/N)" choice
case $choice in
	y|Y) echo "Good!";;
	n|N) echo "Better Luck next time!";;
	*) echo "Invalid Input!";;
esac
for i in {1..10..1}
do
	echo $i
done

Min()
{
	if [[ $arg1 -lt $arg2 ]];
		then echo "$arg1 is smaller"
		else echo "$arg2 is smaller"
	fi
}
Min $n1 $n2
