import socket

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(('localhost', 9999))

marks = input("Enter marks: ")
c.send(marks.encode('UTF-8'))

grade = c.recv(1024).decode('UTF-8')
print('Grade: ', grade)

c.close()