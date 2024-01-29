import socket
HOST = '127.0.0.1' 
PORT = 9999

server = socket.socket()
server.bind((HOST, PORT))
server.listen()

while True:
    print("\nWaiting for incoming connections...\n")
    conn, addr = server.accept()
    
    print("Received connection from ", addr[0], "(", addr[1], ")\n")
    
    s_name = conn.recv(1024).decode("utf-8")
    
    print(s_name, "has connected to the chat room\n")
    name = input(str("Enter your name: "))
    conn.send(name.encode())
    while True:
        message = input(str("Me : "))
        if message == "[e]":
        message = "Left chat room!"
        conn.send(message.encode())
        print("\n")
        break
        conn.send(message.encode())
        message = conn.recv(1024)
        message = message.decode()
        print(s_name, ":", message)