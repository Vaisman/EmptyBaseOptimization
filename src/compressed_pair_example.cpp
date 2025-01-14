#include <type_traits>
#include <utility>
#include <iostream>

template <typename T, bool = std::is_empty_v<T> && !std::is_final_v<T>>
struct EboHelper {
    T value;
    EboHelper() = default;
    explicit EboHelper(const T& val) : value(val) {}

    T& Get() { return value; }
    const T& Get() const { return value; }
};

template <typename T>
struct EboHelper<T, true> : T {
    EboHelper() = default;
    explicit EboHelper(const T& val) : T(val) {}

    T& Get() { return *this; }
    const T& Get() const { return *this; }
};

template <typename T1, typename T2>
struct compressed_pair {
private:
    EboHelper<T1> first;  
    EboHelper<T2> second;

public:
    compressed_pair(const T1& t1, const T2& t2)
        : first(t1), second(t2)
    {}

    T1& GetFirst() { return first.Get(); }
    const T1& GetFirst() const { return first.Get(); }

    T2& GetSecond() { return second.Get(); }
    const T2& GetSecond() const { return second.Get(); }
};


struct EmptyType {};

int main() {
    compressed_pair<EmptyType, int> cp(EmptyType{}, 123);

    std::cout << "sizeof(EmptyType)  = " << sizeof(EmptyType) << std::endl;
    std::cout << "sizeof(cp)         = " << sizeof(cp) << std::endl;
    std::cout << "cp.second()        = " << cp.GetSecond() << std::endl;

    struct AnotherEmpty {};
    compressed_pair<EmptyType, AnotherEmpty> cp2(EmptyType{}, AnotherEmpty{});
    std::cout << "sizeof(cp2) = " << sizeof(cp2) << std::endl;

    return 0;
}