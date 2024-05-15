//
// Created by user on 07.03.2023.
//

#include <cstddef>

template<std::size_t>
struct decl{
    friend constexpr int flag(decl);
};

template<typename Key>
struct def{
    friend constexpr int flag(Key){return 0;}
};

template<auto fn = [](){}>
constexpr auto unique(){
    return fn;
}

template<std::size_t param, int = sizeof(def<decl<param>>)>
constexpr int impl_next(...){
    return param;
}

template<std::size_t param, int = flag(decl<param>{}), auto = unique()>
constexpr int impl_next(int){
    return impl_next<param+1>(int{});
}

template<auto = unique()>
constexpr int next(){
    return impl_next<0>(int{});
}

int main9(){
//    static_assert(next() == 1);
//    static_assert(next() == 2);
//    static_assert(next() == 3);
}