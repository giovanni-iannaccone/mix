#include <cmath>
#include <iostream>
#include <string>

#include "../include/mix/mix.hpp"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

#define EPSILON  1e-6

#define ASSERT(condition, name) do {                                        \
    if (condition) {                                                        \
        std::cout << GREEN << "[+] " << name << RESET << std::endl;         \
    } else {                                                                \
        std::cout << RED << "[-] Failed " << name << RESET << std::endl;    \
        failed++;                                                           \
    }                                                                       \
} while(0)

auto main() -> int {
    int failed = 0;
    mix container;

    container.insert<int>(4);
    container.insert<float>(3.14);
    container.insert<std::string>("Hello");

    ASSERT(container.at<int>(0) == 4, "GetInt");
    ASSERT(fabs(container.at<float>(1) - 3.14) < EPSILON, "GetFloat");
    ASSERT(container.at<std::string>(2) == "Hello", "GetString");
    
    container.remove<std::string>("Hello");
    ASSERT(container.find("Hello") == -1, "Remove");

    std::cout << "----------------------" << std::endl;
    if (failed)
        std::cout << RED    << "[-] Failed " << failed << " tests" << RESET << std::endl;
    else 
        std::cout << GREEN  << "[+] Tests successfully completed" << RESET << std::endl;    

    return 0;
}