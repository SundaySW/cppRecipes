//
// Created by user on 07.03.2023.
//

#include <iostream>
#include "utility"

template<typename, std::size_t>
struct DefInserter{
    friend constexpr auto get(DefInserter);
};

template<typename Key, typename Value>
struct DeclInserter{
    friend constexpr auto get(Key){
        return Value{};
    }
};

template<typename T, std::size_t Index>
struct Caster{
    template<typename U, int = sizeof(DeclInserter<DefInserter<T, Index>, U>)>
        operator U();
};

template <typename U, std::size_t T0, std::size_t ... T>
constexpr auto getSize(std::index_sequence<T0, T...>)
    ->decltype(U{Caster<U, T0>{}, Caster<U, T>{} ...}, std::size_t{0})
{
    return sizeof ... (T) + 1;
}

template<typename U, std::size_t ... Indexes>
constexpr auto getSize(std::index_sequence<Indexes...>){
    return getSize<U>(std::make_index_sequence<(sizeof...(Indexes)-1)>{});
}

struct Foo{
    int i;
    double d;
    char c;
};

int main3(){
    using type = decltype(Foo{}, std::size_t(0));
    std::cout << std::boolalpha << std::is_same<Foo, type>::value << '\n';
    std::cout << std::boolalpha << std::is_same<std::size_t, type>::value << '\n';
    std::cout << getSize<Foo>(std::make_index_sequence<10>{});
}