from socket import *
serverPort=12000
serverSocket=socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('127.0.0.1', serverPort))
serverSocket.listen(1)
print("The server is ready to recieve.")
count=2
while count>0:
    connectionSocket,addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode()
    capitalizedSentence = sentence.upper()
    connectionSocket.send(capitalizedSentence.encode())
    connectionSocket.close()
    count=count-1