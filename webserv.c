/* Sophia Fondell
CS 410 - Assignment 3: webserv.c
11/30/18 */

#include <sys/socket.h>
#include <unistd.h>

// A function to initialize a server
int init(int type, const struct sockaddr *addr, socklen_t alen, int qlen) {
	int fd;
	if ((fd = socket(addr->sa_family, type, 0)) < 0) {
		return -1;
	}
	if (bind(fd, addr, alen) < 0) {
		return -1;
	}
	if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
		if (listen(fd, qlen) < 0) {
			return -1;
		}
	}
	return fd;
}

// Serve incoming requests, fork for each new one
void serve(int fd) {
	int clientfd;
	int status;
	pid_t pid;
	// Set the fd to close after we call exec
	set_cloexec(fd);
	// Accept incoming requests
	for (;;) {
		if ((clientfd = accpet(fd, NULL, NULL)) < 0) {
			perror("shit's fukd fam");
			exit(1);
		}
		// If returned pid is negative something is fucked
		if ((pid = fork()) < 0) {
			perror("shit also fukd here rip");
			exit(1);
		}
		// Forked child process
		else if (pid == 0) {
			if (dup2(clientfd, STDOUT_FILENO) != STDOUT_FILENO || 
				dup2(clientfd, STDERR_FILENO) != STDERR_FILENO) {
				perror("some fd shit is FUCKED");
				exit(1);
			}
			close(clientfd);
			execvp("ps", "ps", "aux", NULL);
		}
		// Parent process
		else {
			close(clientfd);
			// wait for child to execute and write to socket fd
			waitpid(pid, &status, 0);
		}
	}
}

int main(int argc, char* argv[]) {
	struct addrinfo *ailist;
	struct addrinfo *aip;
	struct addrinfo hint;
	int fd;
	int err;
	int n;
	char *host;

	// Too many cmd line args
	if (argc != 1) {
		perror("get fucked");
		exit(1);
	}
	// idk what any of this does but i guess i'll find out eventually
	if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0) {
		n = HOST_NAME_MAX;
	}
	if ((host = malloc(n)) == NULL) {
		perror("getttttt fuckeddddd");
	}
	if (gethostname(host, n) < 0) {
		perror("aaaaaaaaAAAAAAA");
	}
	daemonize("")
	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if ((err = getaddrinfo(host, )))
	return 0;
}







