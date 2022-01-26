#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t size);
static void  (*real_free)(void *ptr);

__attribute__((constructor))
static void init()
{
        real_malloc = dlsym(RTLD_NEXT, "malloc");
        real_free   = dlsym(RTLD_NEXT, "free");
        fprintf(stderr, "init\n");
}

int counter = 0;

void *malloc(size_t size)
{
        void *ptr = real_malloc(size);
        counter += size;
        fprintf(stderr, "Total bytes allocated so far: %zd\n", size);
        return ptr;
}

void free(void *ptr)
{
        real_free(ptr);
}