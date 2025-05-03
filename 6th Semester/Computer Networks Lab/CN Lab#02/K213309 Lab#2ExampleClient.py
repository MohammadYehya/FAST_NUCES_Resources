import socket

s = socket.socket()
print('Socket Created')

s.connect(('localhost', 9999))
print(s.recv(1024).decode())

s.close()

socket.gethostbyname(socket.gethostname())