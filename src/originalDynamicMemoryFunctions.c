
#define _GNU_SOURCE // For dlsym with RTLD_NEXT
//#define RTLD_NEXT (void *)-1
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>


// function pointers
void*(*original_malloc)(size_t size);

void*(*original_calloc)(size_t num, size_t size);

void*(*original_realloc)(void* ptr, size_t size);

void(*original_free)(void* ptr);

// within constructor link to original dynamic memory functions using dlsym... 
int main(void)
{
    original_malloc = dlsym(RTLD_NEXT, "malloc");
    if(!original_malloc)
    {
        write(2, "Error: Could not find original malloc.\n", 40);
        exit(1);
    }

    
    original_calloc = dlsym(RTLD_NEXT, "calloc");
    if(!original_calloc)
    {
        write(2, "Error: Could not find original calloc.\n", 40);
        exit(1);

    }

    original_realloc = dlsym(RTLD_NEXT, "realloc");
    if(!original_realloc)
    {
        write(2, "Error: Could not find original realloc.\n", 41);
        exit(1);
    }

    original_free = dlsym(RTLD_NEXT, "free");
    if(!original_free)
    {
        write(2, "Error: Could not find original free.\n", 48);
        exit(1);
    }


    int * ptrInt = original_malloc(10);
    if(ptrInt == NULL)
    {
        printf("NULL ptr returned");
    }else{
        printf("Memory allocated at address %p\n", ptrInt);
        free(ptrInt);
    }

    printf("\nEnd\n");
    return 0;

}

