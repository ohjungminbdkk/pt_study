#include <stdio.h>
#include <stdint.h>

int main(){
    // https://educoder.tistory.com/entry/cc-int8t-uint8t-int16t-uint16t
    // 1Byteタイプの理解
    // プラットフォームと環境によってbit数が異なる場合があり、
    // uintを利用して、どのプラットフォームと環境にも、
    // 同じbit数を使用する場合に使われる。
    // 以下のsined charとunsigned charは、uintと同じ結果を確認できますが、
    // プラットフォームと環境によって、bit数までは保証できない。
    uint8_t u = 1; // 0~255 = unsigned char
    char c = 1;
    signed char sc = 1;
    unsigned char usc = 1;
    for(int i = 0 ; i <= 255; i++){
        u = i;
        c = i;
        sc = i;
        usc = i;

        printf("i=%d , u = %d , c = %d , sc = %d , usc = %d \n ", i, u, c, sc, usc);
    }
}
