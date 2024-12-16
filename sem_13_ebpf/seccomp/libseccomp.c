#include <stdio.h>
#include <seccomp.h>
#include <unistd.h>

int main() {
    pid_t pid;

    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_KILL);

    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);


    printf ("No restrictions yet\n");

    seccomp_load(ctx);
    pid = getpid();
    printf("!! YOU SHOULD NOT SEE THIS!! My PID is%d\n", pid);

    return 0;
}
