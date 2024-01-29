import socket

HOST="127.0.0.1"
PORT=9999
ADDRESS=(HOST,PORT)

server=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(ADDRESS)

data, client_address = server.recvfrom(1024)

server.sendto(b"Welcome user",client_address)

# try:
#     while True:
# except KeyboardInterrupt:
#     print("Server terminated by user.")
# finally:
    # server.close()
    