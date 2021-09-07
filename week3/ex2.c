#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int arr_len){
    for(int i = 0; i < arr_len-1; i++){
        for(int j = 0; j < arr_len-i-1; j++){
            if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

void print_array(int arr[], int arr_size){
    for(int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }
}
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

int main() {
    int arr[6] = {5, 2, 1, 7, 4, 3};
//    int arr[2] = {4, 1};
    printf("%lu\n", ARR_SIZE(arr));
    bubble_sort(arr, ARR_SIZE(arr));
    print_array(arr, ARR_SIZE(arr));
    return 0;
}
