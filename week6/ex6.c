#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 
#include <sys/wait.h> 

void sigstop_handler(int sig){
	printf("2nd is stopped");
	exit(0);
}

int main(){	
	signal(SIGSTOP, sigstop_handler);
	int fd;
	if(pipe(&fd) < 0){
		printf("Pipe failed");
		return 1;
	}	
	unsigned parent = getpid(); 
	pid_t p1 = 1231, p2 = 1234;
	p1 = fork();			
	p2 = fork();
	if(p1 < 0 || p2 < 0){
		printf("Fork failed");
		return 1;	
	}
	if(p1 > 0 && p2 > 0){	
		FILE *file = fdopen(fd, "w+");
		fprintf(file, "%d", p2);
		printf("Sending pid to 1st child: %d\n", p2);	
		close(fd);		
		wait(NULL);		
	} else if(p1 == 0){
		printf("Wait a couple of seconds\n");		
		FILE *file = fdopen(fd, "r+");
		int p2_;
		fscanf(file, "%d", &p2_);
		close(fd);
		printf("2nd's process pid was taken: %d\n", p2_);		
		kill(p2_, SIGSTOP);
	} else {
		printf("2nd is alive\n");		
	}
}
