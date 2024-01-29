import socket

HOST = '127.0.0.1'
PORT = 9999

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

time=client.recv(1024)
print('Server sent back time :', time.decode("utf-8"))

client.close()