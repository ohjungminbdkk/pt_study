#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;

bool compare(byte a, byte b){
    return a > b;
}

bool execution (bool (*cp)(byte, byte), byte a, byte b){
    return cp(a, b);
}

int main(){
    byte a = 10;
    byte b = 5;

    bool result = execution(compare, a, b);

    printf("result = %d\n", result);

    return 0;
}