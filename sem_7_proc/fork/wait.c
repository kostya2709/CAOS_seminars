#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUMPROC 5

int main(void)
{
  pid_t child[NUMPROC];
  int status[NUMPROC];

  printf("parent = %d\n", getpid());

  for(int i = 0; i < NUMPROC; ++i) {
    if (fork() == 0) {
      sleep(i);
      printf("i=%d, %d\n", i, getpid());
      _exit(i * i);
    }
  }

  for(int i=0; i < NUMPROC; ++i) {
    child[i] = wait(&status[i]);
  }

  for( int i=0; i < NUMPROC; ++i)
    printf("Exit = %d, child = %d\n", WEXITSTATUS(status[i]), child[i]);
}