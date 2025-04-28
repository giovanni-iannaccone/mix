#include <iostream>
#include <string>

#include "../include/mix/mix.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

auto main() -> int {
    int failed;
    mix container;

    container.insert<int>(4);
    container.insert<float>(3.14);
    container.insert<std::string>("Hello");

    if (container.at<int>(0) != 4)
        failed++;
    
    if (container.at<float>(1) != 3.14)
        failed++;
    
    if (container.at<std::string>(2) != "Hello")
        failed++;
    
    container.remove<std::string>("Hello");
    if (container.find("Hello") != -1)
        failed++;

    if (failed)
        std::cout << RED    << "[-] Failed " << failed << " tests" << RESET << std::endl;
    else 
        std::cout << GREEN  << "[+] Tests successfully completed" << RESET << std::endl;    

    return 0;
}