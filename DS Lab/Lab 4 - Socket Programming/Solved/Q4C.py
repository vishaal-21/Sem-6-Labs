import socket

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host = '127.0.0.1'
port = 9999

try:
    client.connect((host, port))
except socket.error as e:
    print(str(e))
    
Response = client.recv(1024)
while True:
    Input = input('Client Say Something: ')
    client.send(str.encode(Input))
    Response = client.recv(1024)
    print('From Server : ' + Response.decode())
    client.close()