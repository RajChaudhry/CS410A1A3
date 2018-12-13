/* Sophia Fondell
CS 410 - Assignment 3: webserv.c
11/30/18 */

#include <sys/socket.h>
#include <unistd.h>
static int const  NOTFOUND = 404;
static int const  NOTIMPL = 501;

void err_case(int code, int client){
    char *buf = malloc(512);
    
    
    //standardized messages found here https://developers.google.com/webmaster-tools/search-console-api-original/v3/errors
    switch(code){
        case NOTFOUND:
            //404 case
            //with the stupid markup stuff
            sprintf(buf, "HTTP/**insert version** ERROR CODE 404 NOT FOUND\r\n");
            write(client, buf, strlen(buf));
            sprintf(buf, "<HTML><head>\n<TITLE> 404 Not Found</title></head>\r\n");
            write(client, buf, strlen(buf));
            sprintf(buf, "<BODY>The specified URL could not be located on our server. \r\n</BODY></HTML>\r\n");
            write(client, buf, strlen(buf));
            break;
        case NOTIMPL:
            sprintf(buf, "HTTP/**insert version** ERROR CODE 501 NOT IMPLEMENTED\r\n");
            write(client, buf, strlen(buf));
            sprintf(buf, "<HTML><head>\n<TITLE> 501 Not Implemented</title></head>\r\n");
            write(client, buf, strlen(buf));
            sprintf(buf, "<BODY>The requested operation has not been implemented. \r\n</BODY></HTML>\r\n");
            write(client, buf, strlen(buf));
            break;
            
        default:
            sprintf(stderr, "Error finding error message lol\n");
            break;
    }
    
    close(client);
    exit(0);
            
}
    

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
		if ((clientfd = accept(fd, NULL, NULL)) < 0) {
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
	// put command name here
	daemonize("commandname")
	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	// put command name here
	if ((err = getaddrinfo(host, "commandname", &hint, &ailist)) != 0) {
		perror("nope");
		exit(1);
	}
	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr,
			aip->ai_addrlen, QLEN)) >= 0) {
			serve(sockfd);
			exit(0);
		}
	}
	exit(1);
}







