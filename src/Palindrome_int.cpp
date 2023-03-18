#include "../include/Palindrome_int.h"
#include <string>
#include <algorithm>


bool Solution::isPalindrome(int x){
   
    // Read the number as string
    std::string number_as_string = std::to_string(x);
    
    // Create a reversed string
    std::string reversed_string = number_as_string;
    std::reverse(reversed_string.begin(), reversed_string.end());
   
    if (number_as_string == reversed_string){
        return true;
    } else {
        return false;
    }
}
