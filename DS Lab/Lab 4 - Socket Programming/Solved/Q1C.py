import socket

HOST = '127.0.0.1'
PORT = 9999

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

data=input("Enter message to send to server : ")
client.send(data.encode("utf-8"))

data=client.recv(1024)
print('Server sent back :', data.decode("utf-8"))

client.close()