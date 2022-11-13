#define _GNU_SOURCE

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>

typedef ssize_t (*execve_func_t)(const char *filename, char *const argv[], char *const envp[]);

static execve_func_t old_execve = NULL;

int execve(const char *filename, char *const argv[], char *const envp[]) {
    printf("[EXEC_HOOK] filename: %s, args: ", filename);
    for(i = 0; argv[i] != '\0'; i++)
    {
        printf("%c ", argv[i]);
    }
    printf(", envs: ");
    for(i = 0; envp[i] != '\0'; i++)
    {
        printf("%c ", envp[i]);
    }
    printf("\n");
    old_execve = dlsym(RTLD_NEXT, "execve");
    return old_execve(filename, argv, envp);
}