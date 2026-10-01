#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <string.h>

int count = 0, max_fd = 0;
int ids[65536];
char *msgs[65536];
fd_set read_fds, write_fds, all_fds;
// WARNING: A lot of repo use 4242 as dimension for the following buffers
// but in the exam there is a test which test with a msg of 200k char and idk how
// but it breaks the array of ids making the value of div[0] weird numbers
// so use a bigger buffer (2M) than the message to avoid that error
char buf_read[2000000], buf_write[2000000];

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return 0;
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return -1;
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_wrong_arg()
{
	write(2, "Wrong number of arguments\n", 26);
	exit(1);
}

void fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void broadcast_msg(int arrived)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &write_fds) && fd != arrived)
			send(fd, buf_write, strlen(buf_write), 0);
	}
}

void remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	broadcast_msg(fd);
	free(msgs[fd]);
	msgs[fd] = NULL;
	FD_CLR(fd, &all_fds);
	close(fd);
}

void register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &all_fds);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
	broadcast_msg(fd);
}

void send_client_msg(int fd)
{
	char *msg;
	int ret;

	while ((ret = extract_message(&(msgs[fd]), &msg)))
	{
		if (ret == -1)
			fatal_error();
		sprintf(buf_write, "client %d: %s", ids[fd], msg);
		broadcast_msg(fd);
		free(msg);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fatal_wrong_arg();
	}

	FD_ZERO(&all_fds);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal_error();
	max_fd = sockfd;
	FD_SET(sockfd, &all_fds);

	struct sockaddr_in serveraddr;	
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serveraddr.sin_port = htons(atoi(argv[1]));

	if ((bind(sockfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)))  != 0)
		fatal_error();
	
	if (listen(sockfd, SOMAXCONN) != 0)
		fatal_error();
	
	while (1)
	{
		read_fds = write_fds = all_fds;
		if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
			fatal_error();
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &read_fds))
				continue;
			if (fd == sockfd)
			{
				// accept
				socklen_t addr_len = sizeof(serveraddr);
				int client_fd = accept(sockfd, (struct sockaddr *)&serveraddr, &addr_len);
				if (client_fd >= 0)
					register_client(client_fd);
			}
			else
			{
				int read_bytes = recv(fd, buf_read, 2000000 - 1, 0);
				if (read_bytes <= 0)
					remove_client(fd);
				else
				{
					buf_read[read_bytes] = '\0';
					char *tmp = str_join(msgs[fd], buf_read);
					if (!tmp)
						fatal_error();
					msgs[fd] = tmp;
					send_client_msg(fd);
				}
			}
		}
	}

	return 0;
}