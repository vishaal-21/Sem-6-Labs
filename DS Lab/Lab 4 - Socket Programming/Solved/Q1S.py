import socket

HOST = '127.0.0.1'
PORT = 9999

server=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()

while True:
    conn, addr = server.accept()
    print('Connected by', addr)
    
    data = conn.recv(1024)
    if data:
        print("Client says : ",data.decode("utf-8"))
    if not data:
        break
    conn.send(bytes(data))
server.close()