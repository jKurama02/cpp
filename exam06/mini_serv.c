#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main (int argc, char **argv)
{
    char buffer[BUFFER_SIZE];
    if (argc < 2 || argv[1] == NULL)
    {
        return 1;
    }
    int server_fd;
    struct sockaddr_in server_addr;

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("sokcet failed");
        exit(EXIT_FAILURE);
    }
    int host_addrlen = sizeof(server_addr);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
    

    if (bind(server_fd, (struct sockaddr *)&server_addr, host_addrlen) == -1)
        {
            // printf("server_fd = %d , host_addrlen = %d \n",server_fd , host_addrlen);
            printf("host_addrlen = %d, atteso = %zu\n", host_addrlen, sizeof(struct sockaddr_in));
            perror("bind");
            exit(EXIT_FAILURE);
        }
    
    if((listen(server_fd , 10)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    printf("server listening for connections\n");

    while(1)
    {
        int client_fd = accept(server_fd, (struct sockaddr *) &server_addr, (socklen_t *) &host_addrlen);
        if(client_fd == -1)
        {
            perror("bind");
            exit(EXIT_FAILURE);
        }
        printf("connection accepted\n");
        int data = read(client_fd , buffer, BUFFER_SIZE);
        if (data < 0) {
            perror("webserver (read)");
            continue;
        }
        write(1 , &data,sizeof(data));
        close(client_fd);
    }
    printf("Port = %d\n", atoi(argv[1]));
    return 0;
}
