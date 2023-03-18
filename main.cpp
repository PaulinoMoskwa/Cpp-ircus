#include "include/Palindrome_int.h"
#include <string>
#include <algorithm>
#include <iostream>


int main() {

    // Palindrome

    Solution solution;

    std::cout << "Is 121 palindrome? " << solution.isPalindrome(121) << std::endl;
    std::cout << "Is -121 palindrome? " << solution.isPalindrome(-121) << std::endl;
    
    return 0;
    
}
