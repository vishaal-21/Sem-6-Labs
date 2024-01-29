import socket

HOST = '127.0.0.1'
PORT = 9999
ADDRESS=(HOST,PORT)

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

client.sendto(b"Request",ADDRESS)

time,server_address = client.recvfrom(1024)
print('Server sent back time :', time.decode("utf-8"))

client.close()