#include "iostream"

struct A { short c; int a; };
struct B { double b; };

int foo(unsigned char A::* ptr){
    A a;
    return a.*reinterpret_cast<int A::*>(ptr);
}

int main7(){
    auto f = &A::a;
    double B::* g = &B::b;
    std::cout << f << std::endl << g << std::endl << foo(reinterpret_cast<unsigned char A::*>(f)) << std::endl;
}