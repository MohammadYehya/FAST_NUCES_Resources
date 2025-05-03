import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 9999))
s.listen(5)

print("Waiting for connections...")


file = open('Chatroom.txt', 'a')

while True:
    (c, address) = s.accept()
    print('Connection from ', address)
    msg = c.recv(1024).decode('UTF-8')
    if msg == 'exit':
        break
    print(f"Client: {msg}")
    file.write(f"Client: {msg}\n")
    file.flush()

    msg = input("Enter a message: ")
    c.send(msg.encode('UTF-8'))

file.close()
s.close()