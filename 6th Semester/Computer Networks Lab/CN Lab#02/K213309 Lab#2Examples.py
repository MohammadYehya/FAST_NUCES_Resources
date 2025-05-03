#Example 1

import socket
hostname = socket.gethostname()
print('HOSTNAME: ', hostname)
#Should print hostname

ipaddress = socket.gethostbyname(hostname)
print('IP Address: ',ipaddress)
#Should print the ip address



#Example 2

ipgoogle =  socket.gethostbyname('google.com')
print('Google IP: ', ipgoogle)
#Should print the ip of google



#Example 3

hostname = socket.gethostbyaddr('8.8.8.8')
print('IP: ', hostname)



#Example 4

def find_service_name():
    protocolName = 'tcp'
    for port in [80, 25, 9, 37, 79]:
        print("Port: %s => Service Name: %s" %(port, socket.getservbyport(port, protocolName)))
    print("Port: %s => Service Name: %s" %(53, socket.getservbyport(53, 'udp')))
find_service_name()



#Example 5
from socket import *
import time

starttime = time.time()

target = input('Enter the host to be scanned: ')
t_IP = gethostbyname(target)
print('Scanning scan on host: ', t_IP)

for i in range (130, 140):
    s = socket(AF_INET, SOCK_STREAM)
    conn = s.connect_ex((t_IP, i))
    if(conn == 0):
        print('Port %d: OPEN' % (i,))
    s.close()
print('Time Taken: ', time.time() - starttime)