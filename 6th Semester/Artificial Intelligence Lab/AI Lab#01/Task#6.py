import csv

def readfile(filename):
    data = []

    file = open(filename, 'r')
    reader = csv.reader(file)
    for row in reader:
        data.append(row)
    return data

filename = 'Task#6.csv'
data = readfile(filename)
print(data)