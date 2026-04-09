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

struct Calc{
    int (*fp)(int, int); // 함수 포인터를 구조체 멤버로 지정
};

//*this 구조체의 주소를 건네주어야 한다.
void Calculator(struct Calc *this, int num1, int num2){
    int result = 0;

    result= (*this).fp(num1, num2);
    printf("result = %d\n", result);
}

int main(){
    int a = 10;
    int b = 5;

    struct Calc c;

    c.fp = sum;
    Calculator(&c, a, b);
    c.fp = sub;
    Calculator(&c, a, b);
    c.fp = div;
    Calculator(&c, a, b);
    c.fp = mul;
    Calculator(&c, a, b);
    
    return 0;
}

//https://dojang.io/mod/page/view.php?id=598
//https://chinensis.tistory.com/entry/C%EC%96%B8%EC%96%B4%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-%EA%B0%9D%EC%B2%B4-%EC%A7%80%ED%96%A5-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D