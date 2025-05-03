import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 9999))
print('Waiting for connection...')
s.listen(1)
(c, addr) = s.accept()
print('Connected to Address: ', addr)

marks = c.recv(1024).decode('UTF-8')
print('Recieved marks')
marks = int(marks)
grade = ''
if marks >= 90:
    grade = 'A+'
elif marks >= 86:
    grade = 'A'
elif marks >= 82:
    grade = 'A-'
elif marks >= 78:
    grade = 'B+'
elif marks >= 74:
    grade = 'B'
elif marks >= 70:
    grade = 'B-'
elif marks >= 66:
    grade = 'C'
elif marks >= 62:
    grade = 'C-'
elif marks >= 58:
    grade = 'D'
elif marks >= 54:
    grade = 'D-'
elif marks >= 50:
    grade = 'E'
else:
    grade = 'F'

c.send(grade.encode('UTF-8'))
print('Sent Grades')
c.close()
s.close()

