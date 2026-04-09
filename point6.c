#include<stdio.h>
#include<stdlib.h>

int main() {
    int **arr;

    arr = malloc(sizeof(int*) * 2);

    //失敗時、NULLを返却がされる
    if(NULL == arr){
        printf("failed");
        return 1;
    }

    arr[0] = malloc(sizeof(int) * 3);
    
    if(NULL == arr[0]){
        printf("failed");
        free(arr);
        arr = NULL;
        return 1;
    }
    arr[1] = malloc(sizeof(int) * 3);

    if(NULL == arr[1]){
        printf("failed");
        free(arr[0]);
        arr[0] = NULL;
        free(arr);
        arr = NULL;
        return 1;
    }
    arr[0][0] = 1;
    arr[1][0] = 2;

    //arrが最後に解除することが重要
    free(arr[1]);
    arr[1] = NULL;

    free(arr[0]);
    arr[0] = NULL;

    free(arr);
    //解除後、NULL初期化
    //freeを使わずに動的確保を行うと、メモリは解除されずに増え続ける。
    arr = NULL;

    //メモリはmallocした単位ごとに解除する。
    //配列の要素（arr[0][0]など）は個別に解除しない。

}