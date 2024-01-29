import socket

HOST="127.0.0.1"
PORT=9999
ADDRESS=(HOST,PORT)

client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

client.sendto(b"Connect",ADDRESS)
data,server_address=client.recvfrom(1024)
print(data)

# try:
#     while True:
# except KeyboardInterrupt:
#     print("Server terminated by user.")
# finally:
#     server.close()
    