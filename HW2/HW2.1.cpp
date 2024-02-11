#include <iostream>

int main(){
    int x=5;
    //pointer p to x's address
    int* p=&x;
    //pointer pp to pointer p's address
    int** pp = &p;
    //cout x's address
    std::cout << *p << std::endl;
    //pointed address increment by 4 aka the memory after x, p no longer points at x
    p++;
    /*
    if you want pointer to change value in pointed address:
    *p = 6;
    */

    // for testing
    //std::cout<<x << std::endl;

    //cout new pointed address
    std::cout << p << " " << *p << std::endl;
    //cout pointed pointer's value which is an address
    std::cout << *pp; 
    return 0;
}