#include<stdio.h>
#include <stdbool.h>

bool compare(int a, int b){
    return a == b;
}
int main(){
    int num = 10;
    int *p = &num;
    int **pp = &p;

    //0x100  (&num) →  10        (num)
    //0x200  (&p)   →  0x100     (p)
    //0x300  (&pp)  →  0x200     (pp)

    printf("num  = %d , &num = %p\n", num, &num);
    printf("*p   = %d , &p   = %p\n", *p, &p);
    printf("**pp = %d , &pp  = %p\n", **pp, &pp);

    printf("num  = %d , &num = %p\n", num, &num);
    printf("*p   = %d , p   = %p\n", *p, p);
    printf("**pp = %d , pp  = %p\n", **pp, pp);

    //&によって、参照が異なる
    printf("&num   = %p           \n", &num);
    printf("&p     = %p , p   = %p\n", &p, p);
    printf("&pp    = %p , pp  = %p\n", &pp, pp);

    printf("compare num(%d) eq *p(%d) = %d\n", num, *p,compare(num, *p));
    printf("compare *p(%d) eq **p(%d) = %d\n", *p, **pp,compare(*p, **pp));

}
