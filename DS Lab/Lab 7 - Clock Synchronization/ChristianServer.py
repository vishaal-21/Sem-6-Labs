import socket
import datetime
import time

HOST='127.0.0.1'
PORT=8888

server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen(5)

while True:
    client_socket,client_address=server_socket.accept()
    print(f"Connected to {client_socket} : {client_address}")
    client_socket.send(str(datetime.datetime.now()).encode())
    client_socket.close()