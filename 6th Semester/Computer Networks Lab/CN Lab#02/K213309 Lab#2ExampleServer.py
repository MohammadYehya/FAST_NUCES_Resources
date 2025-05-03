import socket

s = socket.socket()
print('Socket Created')

s.bind(('localhost', 9999))

s.listen(5)
print('Waiting for connection')
while True:
    c, addr = s.accept()
    print('Got connection from ', addr)
    c.send(bytes('Thank you for connecting!', 'UTF-8'))
    c.close()
s.close()