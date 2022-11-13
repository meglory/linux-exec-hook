#define _GNU_SOURCE

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>

typedef ssize_t (*execve_func_t)(const char *filename, char *const argv[], char *const envp[]);

static execve_func_t old_execve = NULL;

int execve(const char *filename, char *const argv[], char *const envp[]) {
    printf("[EXEC_HOOK] filename: %s, args: %s, env: %s", filename, argv, envp);
    old_execve = dlsym(RTLD_NEXT, "execve");
    return old_execve(filename, argv, envp);
}