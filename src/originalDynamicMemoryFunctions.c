
#include <stdio.h>
// within constructor link to original dynamic memory functions using dlsym...



//original_free(void)(void* ptr) = dlsym("free")... ;  

//original_malloc(void*)(size_t size) = dlysm("malloc")... ;


//original_calloc(void*)(int n_items, size_t size) = dlysm("calloc")... ;


//original_realloc(void*)(void* oldPtr, size_t size) = dlysm("realloc") ... ;
