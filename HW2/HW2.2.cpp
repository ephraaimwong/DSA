#include <iostream>

void Op(int* ptr){
    //cout value at pointed address
    std::cout<<*ptr;
}
int main2(){
    int x;
    int* p=&x;
    int** pp=&p;
    int*** ppp=&pp;
    //valid: &x(refers to address of x and treated like a pointer), p (is a pointer), *pp (parse value of p which is address of x),**ppp(parses single pointer)
    //invalid: x (not a pointer), *p (parses value of x), &p (parses address of pointer), pp (parses address of pp), &pp (parses address of pp), **pp (parses value of x), ppp (address of ppp), *ppp(parses pointer-to-pointer instead of pointer), ***ppp(value of x), &ppp(address of ppp)
    Op();
    return 0;
}