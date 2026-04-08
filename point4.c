#include<stdio.h>

int main(){
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("%d\n", arr[0][0]);
    printf("%d\n", arr[0][1]);
    printf("%d\n", arr[0][2]);
    printf("%d\n", arr[1][0]);
    printf("%d\n", arr[1][1]);
    printf("%d\n", arr[1][2]);

    printf("arr[1][2] = %d\n", arr[1][2]);
    
    //arr[][]
    printf("*(*(arr))   =%d\n", *(*(arr)));
    printf("*(*arr)     =%d\n", *(*arr));
    printf("*(*(arr)+1) =%d\n", *(*(arr)+1));
    printf("*(*arr)+1   =%d\n", *(*arr)+1);
    printf("*(*(arr)+2) =%d\n", *(*(arr)+2));
    printf("*(*arr)+2   =%d\n\n", *(*arr)+2);
;
    printf("*(*(arr+1)+0) =%d\n", *(*(arr+1)+0));
    printf("*(*(arr+1)+1) =%d\n", *(*(arr+1)+1));
    printf("*(*(arr+1)+2) =%d\n", *(*(arr+1)+2));

    printf("*arr[1] = %d\n", *arr[1]); //arr[1][0]
    printf("arr[1][0] = %d\n", arr[1][0]); //arr[1][0]

    printf("(*arr)[1] = %d\n", (*arr)[1]);//arr[0][1]
    printf("arr[0][1] = %d\n", arr[0][1]); //arr[0][1]
}