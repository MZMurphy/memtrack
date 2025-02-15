#include <stdio.h>

int main(void)
{

    int *intPtr = (int *)malloc(sizeof(int));
    if (intPtr == NULL)
    {
        return 1;
    }
    *intPtr = 10;
    printf("%d\n", *intPtr);
    free(intPtr);
    return 0;

    char * charPtr = (char*)calloc(2, sizeof(char));

    int * intPtr2 = (int*)realloc(intPtr, sizeof(int)); // Realloc of same size 

    free(charPtr);
    free(intPtr2);
    printf("currently internal buffers have their memory allocation tracked but not their deallocation"); // This is strange as valgrind can see it ! 

}