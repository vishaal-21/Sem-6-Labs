import socket
from timeit import default_timer as timer
import datetime
from dateutil import parser

HOST='127.0.0.1'
PORT=8888

client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect((HOST,PORT))

request_time=timer()
server_time=parser.parse(client_socket.recv(1024).decode())
response_time=timer()
time_diff=response_time-request_time
print(f"Process Latency : {str(time_diff)}")

actual_time=datetime.datetime.now()
print(f"Client time : {str(actual_time)}")

client_time = server_time + datetime.timedelta(seconds=time_diff/2)
print("Synchronized process client time: " + str(client_time))

error=actual_time-client_time
print("Synchronization error : "+str(error.total_seconds())+" seconds")

client_socket.close()