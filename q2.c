#include <stdio.h>
#include <stdint.h>

int sum(int num1, int num2){
    return num1 + num2;
}

int sub (int num1, int num2){
    return num1 - num2;
}
int div (int num1, int num2){
    return num1 / num2;
}
int mul (int num1, int num2){
    return num1 * num2;
}

int execution(int (*cp)(int, int), int num1, int num2){
    return cp(num1, num2);
}

int main(){
    int a = 10;
    int b = 5;

    int sw = 1;
    int result = 0;

    //int result = execution(sub, a, b);

    // switch(sw){
    //     case 0:
    //         result = sum(a, b);
    //         break;
    //     case 1:
    //         result = sub(a, b);
    //         break;
    //     case 2:
    //         result = div(a, b);
    //         break;
    //     case 3:
    //         result = mul(a, b);
    //         break;
    //     default:
    //         printf("none.\n");
    //         return 1;
    // }

    int (*fp[4])(int, int);
    fp[0] = sum;
    fp[1] = sub;
    fp[2] = div;
    fp[3] = mul;
    
    result = fp[sw](a, b);

    printf("result = %d\n", result);

    return 0;
}

//https://crmerry.tistory.com/21
//https://dojang.io/mod/page/view.php?id=597