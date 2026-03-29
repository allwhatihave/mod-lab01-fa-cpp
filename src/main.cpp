#include <iostream>
#include "fun.h"

int main() {
    const char* testStr = "Hello world 123 hello1 Cplusplus KirillTig";
    
    std::cout << "String: " << testStr << std::endl;
    std::cout << "Task 1: " << faStr1(testStr) << std::endl;
    std::cout << "Task 2: " << faStr2(testStr) << std::endl;
    std::cout << "Task 3: " << faStr3(testStr) << std::endl;

    return 0;
}
