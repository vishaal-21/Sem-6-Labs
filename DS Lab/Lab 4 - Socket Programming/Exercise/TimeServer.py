import socket
import time

HOST = '127.0.0.1'
PORT = 9999

server=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind((HOST, PORT))

while True:
    data, client_address = server.recvfrom(1024)
    
    curr_time=time.ctime(time.time())+"\r\n"
    
    server.sendto(curr_time.encode("ascii"),client_address)