#include <stdio.h>
#include <stdlib.h>

int* generate_ref_arr(size_t sz, size_t page_max);
int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz);

// Driver code
//  Usage: ./program {ref_arr_size} {page_max} {frame_size}
int main(int argc, char** argv) {
    if (argc < 4) return -1;
    
    int ref_arr_sz = atoi(argv[1]);
    int page_max = atoi(argv[2]);
    int frame_sz = atoi(argv[3]);

    //int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int* ref = generate_ref_arr(ref_arr_sz, page_max);
    int page_faults = lru(ref, ref_arr_sz, frame_sz);
    printf("%d (faults)\n", page_faults);
    free(ref);

    return 0;
}

int* generate_ref_arr(size_t sz, size_t page_max) {
    int* ref_arr = (int*) malloc(sizeof(int) * sz);
    
    // TODO :: Generate Random Refernece String
    for (int i = 0; i < sz; i++) {
        ref_arr[i] = rand() % page_max;
        printf("%d ", ref_arr[i]);
    }

    return ref_arr;
}

int lru(int* ref_arr, size_t ref_arr_sz, size_t frame_sz) {
    int i, j;
    int page_faults = 0;
    
    // Initializing frames
    int* frames = (int*) malloc(sizeof(int) * frame_sz);
    for (i=0; i<frame_sz; i++) frames[i] = -1;


    // TODO
    //  Implement LRU Algorithm
    for (i = 0; i < ref_arr_sz; i++) {
        int target = ref_arr[i];
        int is_fault = 1;
        for (j = 0; j < frame_sz; j++) {
            if (frames[j] == target) {
                is_fault = 0;
                break;
            }
        }
        if (is_fault) {
            page_faults++;
            for (j = 0; j < frame_sz; j++) {
                if (frames[j] == -1) {
                    frames[j] = target;
                    break;
                }
            }
        }
    }
    

    return page_faults;
}

