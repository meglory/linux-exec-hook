#define _GNU_SOURCE

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

typedef ssize_t (*execve_func_t)(const char *filename, char *const argv[], char *const envp[]);

static execve_func_t old_execve = NULL;

int execve(const char *filename, char *const argv[], char *const envp[]) {
    printf("\n[EXEC_HOOK] filename: %s, args: ", filename);
    for (size_t i = 0; argv[i] != NULL; ++i) {
        printf("%s ", argv[i]);
    }
    printf(", envs: ");
    for (size_t i = 0; envp[i] != NULL; ++i) {
        printf("%s ", envp[i]);
    }
    printf("\n");
    printf("[EXEC_HOOK] before.");
    int ret = strcmp(argv[1], "java");
    printf("[EXEC_HOOK] after.");
    printf("[EXEC_HOOK] argv1: %s, check result: %d", argv[1], ret);
    if (ret == 0) {
        printf("[EXEC_HOOK] got java process");
    }
    old_execve = dlsym(RTLD_NEXT, "execve");
    return old_execve(filename, argv, envp);
}