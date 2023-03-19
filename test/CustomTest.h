#ifndef CUSTOM_TEST_H
#define CUSTOM_TEST_H

#include<string>


#define GIVEN(msg) \
    std::cout << std::setw(32) << "\033[1;32mGIVEN: \033[0m" << msg << "\n";

#define WHEN(msg) \
    std::cout << std::setw(32) << "\033[1;32mWHEN: \033[0m" << msg << "\n";

#define THEN(msg) \
    std::cout << std::setw(32) << "\033[1;32mTHEN: \033[0m" << msg << "\n";


#endif //CUSTOM_TEST_H