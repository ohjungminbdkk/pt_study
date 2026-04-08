#include<stdio.h>

int main(){
    int arr[3] = {10, 20, 30};

    printf("arr[0] = %d\n", arr[0]);
    printf("*(arr) = %d\n", *(arr));

    printf("arr[1] = %d\n", arr[1]);
    printf("*(arr+1) = %d\n", *(arr+1));

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %d\n", *(arr+2));

    //ポインタが指す値を取得する場合、かっこの有無によって動作が異なる
    //*arrは配列の先頭の値を取得するが、
    //*arr+1は先頭の値に対して+1にする
    printf("arr[0] = %d\n", arr[0]);
    printf("*arr = %d\n", *arr);

    printf("arr[1] = %d\n", arr[1]);
    printf("*arr+1 = %d\n", *arr+1);

    printf("arr[2] = %d\n", arr[2]);
    printf("*arr+2 = %d\n", *arr+2);

    // addr
    printf("arr[0] = %d\n", arr[0]);
    printf("*(arr) = %p\n", (arr));

    printf("arr[1] = %d\n", arr[1]);
    printf("*(arr+1) = %p\n", (arr+1));

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr+2) = %p\n", (arr+2));

    //*とかっこない場合、影響がない、配列の順調として扱う
    printf("arr[0] = %d\n", arr[0]);
    printf("(arr) = %p\n", arr);

    printf("arr[1] = %d\n", arr[1]);
    printf("arr+1 = %p\n", arr+1);

    printf("arr[2] = %d\n", arr[2]);
    printf("arr+2 = %p\n", arr+2);

}