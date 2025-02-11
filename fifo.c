#include <stdio.h>
#include <stdlib.h>

#define EMPTY_FRAME -1

int* generate_ref_arr(size_t sz, size_t page_max);
void fifo(int* ref_arr, size_t ref_arr_sz, size_t frame_sz);

int _contains(int* arr, size_t sz, int target);

// Driver code
int main(void) {
   
   int* ref= generate_ref_arr(20, 10);
   int sz = sizeof(&ref) / sizeof(int);

  fifo(ref, sz, 4);
    return 0;
}

int* generate_ref_arr(size_t sz, size_t page_max) {
    int* ref_arr = (int*) malloc(sizeof(int) * sz);
    // TODO ::
    //  Generate Refernece String

    for (size_t i = 0; i < sz; i++) {
        ref_arr[i] = (rand() % page_max);
    }  
  return ref_arr;
   
}

void fifo(int* ref_arr, size_t ref_arr_sz, size_t frame_sz) {
    int i, j, is_fault;
    int page_faults = 0, target = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = EMPTY_FRAME;

    // Iterating reference string
    for (i=0; i<ref_arr_sz; i++) {
        is_fault = _contains(frames, frame_sz, ref_arr[i]);

        // Miss (page fault occurred)
        if (is_fault == -1) {
            frames[target] = ref_arr[i];
            target = (target + 1) % frame_sz;
            page_faults++;
        }

        // Printing current states of frames
        printf("%d | ", ref_arr[i]);
        for(j=0; j<frame_sz; j++) {
            if (frames[j] == EMPTY_FRAME) printf(". ");
            else printf("%d ", frames[j]);
        }
        if (is_fault == -1) printf("(fault)");
        printf("\n");
    }

    // Releasing memory
    free(frames);
}

int _contains(int* arr, size_t sz, int target) {
    int i = 0;
    for (i=0; i<sz; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}