#include <stdio.h>

int main(){
    // 値なら → %d
    // アドレスなら → %p
    // 値を取り出すときは → *
    // アドレスを取得するときは → &

    int num01 = 10;
    int num02 = 20;
    int num03 = 10;
    int *ref_num01 = &num01;
    int *ref_num02 = &num02;
    
    //出力形式確認
    //intタイプ %d
    printf("num01 val = %d\n", num01);
    printf("num02 val = %d\n", num02);

    //値を出力する時 *ref_num01 %d
    printf("ref_num01 val = %d\n", *ref_num01);
    printf("ref_num02 val = %d\n", *ref_num02);

    //住所をを出力する時 ref_num01 %p
    printf("ref_num01 val = %p\n", ref_num01);
    printf("ref_num02 val = %p\n", ref_num02);

    //値を比較する時
    printf("%d\n", *ref_num01 == num01);
    printf("%d\n", *ref_num02 == num02);
    printf("%d\n", *ref_num01 == num02);
    printf("%d\n", *ref_num02 == num01);
    printf("%d\n", num03 == num01);


    //住所を比較する時
    printf("%d\n", ref_num01 == &num01);
    printf("%d\n", ref_num02 == &num02);
    printf("%d\n", ref_num01 == &num02);
    printf("%d\n", ref_num02 == &num01);

    printf("num01 addr = %p\n", &num01);
    printf("num02 addr = %p\n", &num02);
    printf("ref_num01 addr = %p\n", ref_num01);
    printf("ref_num02 addr = %p\n", ref_num02);
}