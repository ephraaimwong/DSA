#include <iostream>

void Op1(int* ptr){
    std::cout<<*ptr;
}
//reference to pointer, changes to pointer within func affects original pointer
void Op2(int*& ptr){
    std::cout<<*ptr;
}
int main3(){
    int x;
    //valid
    Op1(&x);
    //invalid
    Op2(&x);
    /* to be valid:
    int* p=&x;
    Op2(p);
    */
    return 0;
}
