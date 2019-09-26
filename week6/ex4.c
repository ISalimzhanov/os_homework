#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>

void sigkill_handler(int sig){
	printf("killed\n");
	exit(0);
}

void sigstop_handler(int sig){
	printf("stopped\n");
	exit(0);
}

void sigusr1_handler(int sig){
	printf("killed by user\n");
	exit(0);
}


int main(){	
	signal(SIGKILL, sigkill_handler);
	signal(SIGSTOP, sigstop_handler);
	signal(SIGUSR1, sigusr1_handler);
	while(1){
		printf("%d\n", getpid());	
	}
	return 0;
}
