#include<stdio.h>
#include<stdlib.h>

int main() {
    int **arr;

    //進行中
    arr = malloc(sizeof(int*) * 2);

    arr[0] = malloc(sizeof(int) * 3);
    arr[1] = malloc(sizeof(int) * 3);

    arr[0][0] = 1;
    arr[1][0] = 2;

    free(arr[1]);
    free(arr[0]);
    free(arr);

}