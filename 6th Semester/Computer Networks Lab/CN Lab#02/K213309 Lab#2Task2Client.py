import socket

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(('localhost', 9999))
file = open('Chatroom.txt', 'a')

while True:
    msg = input("Enter a message: ")
    c.send(msg.encode('UTF-8'))
    if(msg == 'exit'):
        break

    msg = c.recv(1024).decode('UTF-8')
    print(f"Server: {msg}")
    file.write(f"Server: {msg}\n")
    file.flush()

file.close()
c.close()