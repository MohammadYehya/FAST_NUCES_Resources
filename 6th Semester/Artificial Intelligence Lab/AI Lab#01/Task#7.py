def intcharfinder(str):
    letters = 0
    numbers = 0

    for i in str:
        if i.isdigit():
            numbers += 1
        elif i.isalpha():
            letters += 1
    print(str, '\nNumber of Integers: ', numbers, '\nNumber of Letters: ', letters, '\n')

intcharfinder('Hello123')
intcharfinder('123')
intcharfinder('Hello')