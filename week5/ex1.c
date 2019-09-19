//
// Created by Iskander on 19.09.2019.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int i;

void *new_thread(void *vargp){
	printf("thread N: %d.\nsome text\n", i + 1);
	pthread_t id = pthread_self();
	pthread_exit(&id);
}

int main(){
    int n;
    scanf("%d", &n);
    pthread_t threads[(const int)(n)];
    for(i = 0; i < n; ++i) {
        pthread_create(&threads[i], NULL, new_thread, NULL);
	pthread_join(threads[i], NULL);
    }
}
