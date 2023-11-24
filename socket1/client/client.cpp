#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) == -1) {
        perror("Connection failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int client_cnt = 0;
    while (true) {
        const char* message = "Hello from client!";
        send(clientSocket, message, strlen(message), 0);

        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            break;
        }

        std::cout << "Received from server: " << buffer << std::endl;

        client_cnt++;
        std::cout<<"client cnt : "<<client_cnt<<std::endl;
        if(client_cnt==10)
        {
            close(clientSocket);
        }


        sleep(1); // 每隔1秒发送一次数据
    }

    close(clientSocket);

    return 0;
}
