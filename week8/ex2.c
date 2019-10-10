#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
	for(int i = 0; i < 10; ++i){
		char *arr = (char *) malloc((1 << 20));
		memset(arr, 0, sizeof(char) * (1 << 20));
		sleep(1);	
	}
	return 0;
}
