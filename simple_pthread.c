#include "stdio.h"
#include "pthread.h"

pthread_mutex_t lock;
int num = 0;

void *worker_a(void *var){
  int i;
  for(i = 0; i< 50; i++){
    pthread_mutex_lock(&lock);
    num++;
    printf("From A: num = %d\n", num);
    pthread_mutex_unlock(&lock);
  }
  printf("\nA done.\n");
}

void *worker_b(void *var){
  int i;
  for(i = 0; i< 50; i++){
    pthread_mutex_lock(&lock);
    num++;
    printf("From B: num = %d\n", num);
    pthread_mutex_unlock(&lock);
  }
  printf("\nB done.\n");
}

void *worker_c(void *var){
  int i;
  for(i = 0; i< 50; i++){
    pthread_mutex_lock(&lock);
    num++;
    printf("From C: num = %d\n", num);
    pthread_mutex_unlock(&lock);
  }
  printf("\nC done.\n");
}

int main(int argc, char const *argv[]) {

  pthread_t p1, p2, p3;

  printf("Creating threads\n");

  pthread_create(&p1, NULL, worker_a, NULL);
  pthread_create(&p2, NULL, worker_b, NULL);
  pthread_create(&p3, NULL, worker_c, NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  pthread_join(p3, NULL);

  printf("All threads joined\n");

  return 0;
}
