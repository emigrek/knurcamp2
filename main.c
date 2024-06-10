#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

const char* STATIC_RESPONSE =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Content-Length: 155\r\n"
        "Server: KNURCAMP SERVER 2137\r\n"
        "Accept-Ranges: bytes\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html>\r\n"
        "  <head>\r\n"
        "    <title>An Example Page</title>\r\n"
        "  </head>\r\n"
        "  <body>\r\n"
        "    <p>Hello World, this is a very simple HTML document.</p>\r\n"
        "  </body>\r\n"
        "</html>";

const char* STATIC_RESPONSE_SUCHA_KREWETA =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Server: KNURCAMP SERVER 2137\r\n"
        "Accept-Ranges: bytes\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html>\r\n"
        "  <head>\r\n"
        "    <title>Suchy Kreweta</title>\r\n"
        "  </head>\r\n"
        "  <body>\r\n"
        "    <p>Hello this is suchy kreweta.</p>\r\n"
        "  </body>\r\n"
        "</html>";


#define INPUT_BUFFER_SIZE 4096
#define MAX_CLIENTS       1024

void find_path(const char* request, char* target) {
    while(*(request)++ != ' ') {}
    while(*request != ' ') {
        *(target)++ = *(request)++;
    }
    *target = 0x00;
}

int find_free_socket(int* sockets, int size) {
    for(int i=0;i<size;i++)
    {
        if(sockets[i] == 0)
            return i;
    }
    return -1;
}

const char* router(const char* path)
{
    if(strcmp("/suchyKreweta", path) == 0) {
        return STATIC_RESPONSE_SUCHA_KREWETA;
    }
    else if(strcmp("/vanish", path) == 0) {
        return NULL;
    }
    else {
        return STATIC_RESPONSE;
    }
}

void handler_sig13(int signum)
{
    printf("Broken pipe error\n");
}

int main(void) {
    signal(13, handler_sig13);

    char input_buffer[INPUT_BUFFER_SIZE + 1];
    char path_buffer[1024];
    char ip_buffer[16];

    struct sockaddr_in client_data;
    socklen_t size = sizeof(client_data);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        printf("server socket ret -1\n");
        exit(-1);
    }

    int fcntl_status = fcntl(server_socket, F_SETFL, O_NONBLOCK);
    if (fcntl_status == -1) {
        perror("calling fcntl");
    }

    int clients[MAX_CLIENTS];
    for(int i = 0; i < MAX_CLIENTS;i++)
    {
        clients[i] = 0;
    }

    struct sockaddr_in sai;
    sai.sin_addr.s_addr = inet_addr("0.0.0.0");   
    sai.sin_family = AF_INET;                       
    sai.sin_port = htons(8181);                     
    memset(sai.sin_zero, 0, 8);                     

    int ret = bind(server_socket, (struct sockaddr*)&sai, sizeof(sai));
    if(ret != 0)
    {
        printf("server bind failed\n");
        exit(-1);
    }

    ret = listen(server_socket, 1024);
    if(ret != 0)
    {
        printf("server listen failed\n");
        exit(-1);
    }

    while(1) {
        while(1) {
            int client_socket = accept(server_socket, (struct sockaddr *)&client_data, &size);
            if (client_socket == -1) 
                break;

            int free_socket = find_free_socket(clients, MAX_CLIENTS);
            if (free_socket == -1) {
                printf("Max clients reached (%d)\n", MAX_CLIENTS);
                shutdown(client_socket, SHUT_RDWR);
                close(client_socket);
            }

            printf("Accepted connection from %s:%d\n", inet_ntop(AF_INET, &client_data.sin_addr.s_addr, ip_buffer, 16),
                    ntohs(client_data.sin_port));

            fcntl(client_socket, F_SETFL, O_NONBLOCK);
            clients[free_socket] = client_socket;
        }

        for(int i=0;i<MAX_CLIENTS;i++) {
            if(clients[i] == 0) 
                continue;

            size_t received = recv(clients[i], input_buffer, INPUT_BUFFER_SIZE, 0);
            input_buffer[received] = 0x00;

            if (received == -1) {
                if(errno != EWOULDBLOCK && errno != EAGAIN)
                {
                    printf("Error occured on socket, closing connection %d.\n", i);
                    shutdown(clients[i], SHUT_RDWR);
                    close(clients[i]);
                    clients[i] = 0;
                }
                continue;
            }

            find_path(input_buffer, path_buffer);
            printf("Requested path:\n%s by socket %d\n", path_buffer, i);

            const char *response = router(path_buffer);
            if (response == NULL) {
                shutdown(clients[i], SHUT_RDWR);
                close(clients[i]);
                clients[i] = 0;
                break;
            }

            send(clients[i], response, strlen(response), 0);
        }
    }

    shutdown(server_socket, SHUT_RDWR);
    close(server_socket);
    return 0;
}