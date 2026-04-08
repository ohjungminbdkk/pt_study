#include<stdio.h>
#include<stdlib.h>

int main() {
    int size = 5;
    // mallocを用いて、メモリを確報(Heapメモリ) 
    int *arr = (int *)malloc(sizeof(int) * size);

    //初期化
    for (int i= 0; i < size; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    //メモリを返却
    free(arr);

}