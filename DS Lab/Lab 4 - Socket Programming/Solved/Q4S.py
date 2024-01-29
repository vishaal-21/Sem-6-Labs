import socket
import os
from _thread import *

server = socket.socket()
host = '127.0.0.1'
port = 9999
ThreadCount = 0

try:
    server.bind((host, port))
except socket.error as e:
    print(str(e))

server.listen(5)
print('Waiting for a Connection..')

def threaded_client(connection):
    connection.send(str.encode('Welcome to the Server'))
    while True:
        data = connection.recv(2048)
        print('Received from client ' + str(ThreadCount) + ': ' + data.decode())
        Inputs = input('Server Says: ')
        if not data:
            break
        connection.sendall(Inputs.encode())
    connection.close()

try:
    while True:
        conn, addr = server.accept()
        print('Connected to: ' + addr[0] + ':' + str(addr[1]))
        
        start_new_thread(threaded_client, (conn, ))
        ThreadCount += 1
        print('Thread Number: ' + str(ThreadCount))
except KeyboardInterrupt:
    print("Closing")
    server.close()