#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int sig){
	printf("/F\n");
	exit(0);
}

int main(){
	signal(SIGINT, sigint_handler);
	while(1){}
	return 0;
}
