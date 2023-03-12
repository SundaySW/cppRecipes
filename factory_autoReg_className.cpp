#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include <string_view>

struct object {
    virtual ~object() {}
    virtual const char* name() const = 0;
};

struct factory {

    std::map<std::string_view, std::function<std::unique_ptr<object>()>> factories;

    void reg(const char* clazz, std::function<std::unique_ptr<object>()> creator) {
        factories[clazz] = std::move(creator);
    }
    std::unique_ptr<object> create(const char* clazz)  const {
        auto it = factories.find(clazz);
        if (it != factories.end()){
            return it->second();
        }
        throw "cannot create object: unknown class name";
    }
    static factory& global() {
        static factory f;
        return f;
    }
};

template<typename T>
struct registrator {
    registrator(const char* clazz) {
        factory::global().reg(clazz, []() {
            return std::make_unique<T>();
        });
    }
};

#define REG(clazz) static registrator<clazz> global_factory_registrator_of_##clazz(#clazz);

int main1()
{
    factory& f = factory::global();
    auto foo = f.create("foo");
    auto boo = f.create("boo");
    std::cout << foo->name() << std::endl;
    std::cout << boo->name() << std::endl;
}

struct foo : object {
    virtual const char* name() const override{
        return "foo";
    }
};
REG(foo);
struct boo : object {
    virtual const char* name() const override{
        return "boo";
    }
};
REG(boo);