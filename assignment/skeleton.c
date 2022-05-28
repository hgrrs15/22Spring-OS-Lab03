#include <stdio.h>
#include <stdlib.h>

int* generate_ref_arr(size_t sz, size_t page_max);
void function(int* ref_arr, size_t ref_arr_sz, size_t frame_sz);

// Driver code
int main(void) {
    // #1
    int ref[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int sz = sizeof(ref) / sizeof(int);
    function(ref, sz, 3);

    // #2
    int sz = 50;
    int* ref = generate_ref_arr(sz, 9);
    function(ref, sz, 5);
    free(ref);

    return 0;
}

int* generate_ref_arr(size_t sz, size_t page_max) {
    int* ref_arr = (int*) malloc(sizeof(int) * sz);
    
    // TODO ::
    //   Generate Refernece String

    return ref_arr;
}

void function(int* ref_arr, size_t ref_arr_sz, size_t frame_sz) {
    int i, j;
    int page_faults = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = -1;

    // TODO ::
    //   
}