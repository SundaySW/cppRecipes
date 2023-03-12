//
// Created by user on 07.03.2023.
//

#include <string>
#include <type_traits>
#include <cstddef>
#include <iostream>
#include "utility"

template<int N> struct tag{};

template<typename T, int N>
struct loophole_t {
    friend auto loophole(tag<N>) { return T{}; };
};

struct Foo{
    volatile int c = 0;
};

auto loophole(tag<0>);

int main2() {
    sizeof(loophole_t<Foo, 0>);
    static_assert(std::is_same< Foo, decltype(loophole(tag<0>{})) >::value);
    std::cout << std::boolalpha << std::is_same<Foo, decltype(loophole(tag<0>{}))>::value << '\n';
}