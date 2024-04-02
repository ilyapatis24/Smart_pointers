#include <iostream>
#include <memory>

#include "UniquePtr.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    auto ptr = UniquePtr<int>(new int(10));
    std::cout << "ptr = " << *ptr << std::endl;
    std::cout << "ptr = " << ptr.release() << '\n';
    return 0;
}