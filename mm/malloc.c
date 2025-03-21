// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>


void *malloc(size_t size)
{
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) {
        return NULL;
    }
    int res = mem_list_add(p, size);
    if (res < 0) {
        munmap(p, size);
        return NULL;
    }
    return p;
}

void *calloc(size_t nmemb, size_t size)
{
    void *p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) {
        return NULL;
    }
    return p;
}

void free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
    struct mem_list *mem_block = mem_list_find(ptr);
    if (mem_block != NULL) {
        int res = munmap(ptr, mem_block->len);
        if (res == 0) {
            mem_list_del(ptr);
        }
    }
}

void *realloc(void *ptr, size_t size)
{
	if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(size);
    if ((ptr != NULL) && (new_ptr != NULL)) {
            struct mem_list *mem_block = mem_list_find(ptr);
            if (mem_block != NULL) {
                memcpy(new_ptr, ptr, MIN(size, mem_block->len));
                free(ptr);
            }
    }
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    int res = realloc(ptr, nmemb * size);
    return res;
}
