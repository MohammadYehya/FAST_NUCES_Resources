import numpy as np



#Task1
arr1 = np.array([1,2,3,4,21,3309])
arr2 = np.array([5,6,7,8,21,3309])
print(arr1+arr2)



#Task2
print(arr1 * 2) 
#OR
print(np.multiply(arr1, 2))



#Task3
print(np.reshape(arr1, (2,3)))



#Task4
print(arr2.astype(bool))



#Task5
arr3 = np.arange(0, 101, 2, int)
print(arr3)



#Task6
print(np.where(arr1 == arr2)[0])