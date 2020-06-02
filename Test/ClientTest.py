from socket import *
severName = "127.0.0.1"
serverPort=12000
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((severName,serverPort))
sentense=input('Input Lower Case Sentense:')
clientSocket.send(sentense.encode())
modifiedSentense=clientSocket.recv(1024)
print("From Server: ",modifiedSentense.decode())
clientSocket.close()