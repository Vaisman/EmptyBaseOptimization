#include <iostream>
#include <string>
#include <type_traits>

struct EmptyStruct 
{
};

struct MyClass {
    [[no_unique_address]] EmptyStruct emptyMember;
    int data = 42;
};

int main() {
    MyClass obj;

    std::cout << "sizeof(EmptyStruct) = " << sizeof(EmptyStruct) << std::endl;
    std::cout << "sizeof(MyClass) = " << sizeof(MyClass) << std::endl;
    std::cout << "obj.data = " << obj.data << std::endl;

    return 0;
}
