#include <iostream>
#include <test2.cpp>
#include <test1.h>

int main(int, char**) {

    std::cout << TAG << std::endl;

    print_1();

    std::cout << "Hello, world!\n";
}
