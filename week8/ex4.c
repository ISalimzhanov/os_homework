#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
	struct rusage usage;
	for(int i = 0; i < 10; ++i){
		char *arr = (char *) malloc(sizeof(char) * (1 << 20));
		memset(arr, 0, sizeof(char) * (1 << 20));
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);	
	}
	return 0;
}

