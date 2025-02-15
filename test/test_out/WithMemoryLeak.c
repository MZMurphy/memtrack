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

    int * intPtr2 = (int*)realloc(intPtr, 25); // Realloc of same size.

    free(charPtr);
    //free(intPtr2); // we do not free this pointer so there is a memory leak.

}