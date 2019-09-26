#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 
#include <sys/wait.h> 

//ex1 and ex2

int main(){
	int fd1[2], fd2[2];
	char str[50];
	pid_t p;
	if(pipe(fd1) < 0 || pipe(fd2) < 0){
		printf("Pipe failed");
		return 1;	
	}	
	scanf("%s", str);
	p = fork();
	if(p > 0){
		close(fd1[0]);
		write(fd1[1], str, strlen(str) + 1);
		close(fd1[1]);
		wait(NULL);
		close(fd2[1]);
		char str_[50];
		read(fd2[0], str_, strlen(str) + 1);
		printf("%s", str_);		
		close(fd2[0]);
	} else if(p == 0){
		close(fd1[1]);
		char str_[50];
		read(fd1[0], str_, strlen(str) + 1);
		close(fd1[0]);
		close(fd2[0]);
		write(fd2[1], str_, strlen(str) + 1);
		close(fd2[1]);
	} else {
		printf("Fork failed");
		return 1;	
	}
	return 0;
}
