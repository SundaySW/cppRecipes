#include "array"
#include "ranges"

constexpr auto one_of(auto val, auto ... variants){
    return ((val == variants) || ...);
}

template<typename T>
struct OneOf{
    std::initializer_list<T> args;
    constexpr OneOf(std::initializer_list<T> args)
        :args(args)
    {}
    bool operator==(const T& val) const{
        return std::ranges::find(args, val) != args.end();
    }
};

template<std::size_t N, typename ... Values>
constexpr auto make_flag(Values ... values){
    std::array<bool, N> flags{};

    ((flags[static_cast<size_t>(values)] = true), ...); //pack in_place

    return flags;
}

template<typename ... Ts>
struct pack{
    using types_tuple = std::tuple<Ts...>;
};

template<typename ... Ts>
constexpr auto iterate_pack(Ts&&... args){
    ([]<typename T>(T arg){
        //
    }.template operator()<Ts>(args), ...);
}

template<typename ... Ts>
constexpr void reverse_iterate_pack(Ts&&... args){
    (std::ignore = ... = ([]<typename T>(T arg){
        //
    }(args)));
}

template<typename ... Ts>
constexpr void descendingPrint(Ts&... args){
    auto _ = 0;
    auto call = []<typename T>(T arg){};
    ((call(args), _) = ...);
}