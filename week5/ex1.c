//
// Created by Iskander on 19.09.2019.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlbi.h>
#include <uninstd.h>

void new_thread(void *vargp){
    printf("some text\n");
    return NULL;
}

int main(){
    int n;
    scanf("%d", &n);
    pthread_t threads[(const int)(n)];
    for(int i = 0; i < n; ++i) {
        pthread_create(&threads[i], NULL, new_thread, NULL);
        pthread_join(threads[i], NULL);
        exit(0);
    }
}