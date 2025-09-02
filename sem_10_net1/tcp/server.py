import socket

# Define the server address and port
HOST = '0.0.0.0'    # Loopback
PORT = 8080         # Port to listen on

# Create a socket object
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Bind the socket to the address and port
    s.bind((HOST, PORT))
    # Listen for incoming connections
    s.listen()
    print(f"Server listening on {HOST}:{PORT}")
    
    # Accept a connection
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        while True:
            # Receive data from the client
            data = conn.recv(1024)
            if not data:
                break
            # Send the received data back to the client
            conn.sendall(data)

