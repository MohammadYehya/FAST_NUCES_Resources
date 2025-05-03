import socket

def find_service_name(port):
    protocolName = 'tcp'
    print("Port: %s => Service Name: %s" %(port, socket.getservbyport(port, protocolName)))
find_service_name(int(input('Enter port: ')))