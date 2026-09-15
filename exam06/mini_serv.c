#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>


int main (int argc, char **argv)
{
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

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
        err(EXIT_FAILURE, "bind");



    printf("Port = %d\n", atoi(argv[1]));
    return 0;
}
