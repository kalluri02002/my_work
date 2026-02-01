#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>

void sigsegv_handler(int sig, siginfo_t *info, void *context) {
    fprintf(stderr, "Segmentation fault ..!!\n");
    fprintf(stderr, "Address 0x%lx caused error\n", (long)info->si_addr);
    exit(EXIT_FAILURE);
}

void cause_segfault() {
    int *ptr = NULL;  // Creating a NULL pointer dereference
    *ptr = 42;        // This will cause a segmentation fault
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    
    cause_segfault();
    
    return 0;
}

