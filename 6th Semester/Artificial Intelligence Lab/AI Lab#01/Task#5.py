arr = ['A', 2, 'C', 'D', 5, 'A']

def removeDuplicates(arr):
    if(len(arr)-len(set(arr))):
        print('Duplicates exist in the array!')
    else:
        print('No Duplicates in the array!')
    return list(set(arr))

print(removeDuplicates(arr))