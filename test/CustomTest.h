#ifndef CUSTOM_TEST_H
#define CUSTOM_TEST_H

#include<string>

std::string Green = "\033[1;32m";
std::string GreenEnd = "\033[0m";


#define GIVEN(msg) \
    std::cout << std::setw(32) << Green + "GIVEN: " + GreenEnd << msg << "\n";

#define WHEN(msg) \
    std::cout << std::setw(32) << Green + "WHEN: " + GreenEnd << msg << "\n";

#define THEN(msg) \
    std::cout << std::setw(32) << Green + "THEN: " + GreenEnd << msg << "\n";


#endif //CUSTOM_TEST_H