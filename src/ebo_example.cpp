#include <iostream>
#include <string>

struct Empty1 {};
struct Empty2 {};

class DerivedEBO : private Empty1, private Empty2 {
public:
    explicit DerivedEBO(int x) : x(x) {}
    int get() const { return x; }

private:
    int x;
};

int main() {

    DerivedEBO obj(42);

    std::cout << "sizeof(Empty1) = " << sizeof(Empty1) << std::endl;
    std::cout << "sizeof(Empty2) = " << sizeof(Empty2) << std::endl;
    std::cout << "sizeof(DerivedEBO) = " << sizeof(DerivedEBO) << std::endl;
    std::cout << "obj.get() = " << obj.get() << std::endl;

    return 0;
}
