#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

int main() {
    // 创建服务器套接字
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation error");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 绑定服务器地址
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding error");
        return 1;
    }

    // 监听连接
    if (listen(server_fd, 5) == -1) {
        perror("Listening error");
        return 1;
    }

    // 创建 epoll 实例
    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("Epoll creation error");
        return 1;
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_fd;

    // 将服务器套接字添加到 epoll 监听
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        perror("Epoll control error");
        return 1;
    }

    const int MAX_EVENTS = 10;
    struct epoll_event events[MAX_EVENTS];

    while (true) {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, 1000);  // 1秒超时

        for (int i = 0; i < num_events; ++i) {
            int fd = events[i].data.fd;

            if (fd == server_fd) {
                // 有新的连接请求
                struct sockaddr_in client_addr;
                socklen_t client_len = sizeof(client_addr);
                int client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
                if (client_socket == -1) {
                    perror("Accept error");
                    continue;
                }

                std::cout << "Accepted connection from " << inet_ntoa(client_addr.sin_addr) << std::endl;

                event.events = EPOLLIN;
                event.data.fd = client_socket;

                // 将客户端套接字添加到 epoll 监听
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &event) == -1) {
                    perror("Epoll control error");
                    return 1;
                }
            } else {
                // 处理客户端套接字
                char buffer[1024];
                ssize_t num_bytes = recv(fd, buffer, sizeof(buffer), 0);

                if (num_bytes <= 0) {
                    // 客户端断开连接
                    std::cout << "Client disconnected" << std::endl;
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    return -1;
                } else {
                    // 处理从客户端接收到的数据
                    std::cout << "Received: " << buffer << std::endl;

                    // 向客户端发送数据
                    const char *response = "Server response";
                    send(fd, response, strlen(response), 0);
                }
            }
        }
    }

    close(server_fd);
    return 0;
}
