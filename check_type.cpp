//
// Created by 79162 on 12.03.2023.
//
#include <iostream>
#include "array"

template<
    typename Class,
    template<typename T, std::size_t Size> typename Container
>
    struct check: std::false_type {
    };

template<
    typename T, std::size_t Size,
    template<typename, std::size_t> typename Container
>
    struct check<Container<T,Size>, Container>: std::true_type{

    };

int main(){
    std::cout << std::boolalpha << check<std::array<int, 5>, std::array>::value;
};