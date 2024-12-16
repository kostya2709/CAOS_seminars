#include <linux/seccomp.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <stdio.h>


int main () {
  printf("Step 1: no restrictions yet\n");

  prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT);
  printf("Step 2: entering the strict mode. Only read(), write(), exit() and sigreturn() syscalls    are allowed\n");

  pid_t pid = getpid ();
  printf ("!!YOU SHOULD NOT SEE THIS!! My PID = %d", pid);

  return 0;
}
