#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 
#include <sys/wait.h> 

void sigterm_handler(int sig){
	printf("I'm dead");
	exit(0);
}

int main(){	
	signal(SIGTERM, sigterm_handler);
	unsigned pid = getpid(); 
	pid_t p = fork();
	if(p < 0){
		printf("fork failed");
		return 1;	
	}
	if(p > 0){
		sleep(10);
		kill(p, SIGTERM);
	} else {
		while(1){
			printf("I'm alive\n");		
		}	
	}
}
