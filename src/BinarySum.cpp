#include "../include/BinarySum.h"
#include <algorithm>


std::string Solution::addBinary(std::string a, std::string b) {

    // Reverse strings
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    // Extract string lengths
    int long_string_len = std::max(a.size(), b.size());
    int short_string_len = std::min(a.size(), b.size());
    int len_diff = long_string_len - short_string_len;

    // Copy the longer string
    std::string long_string = get_longer_string(a, b, long_string_len);
    
    // Initialize the resulting string (build in reverse)
    std::string result = "";

    // Sum the two strings (until the shortest ends) and, if there is, save the extra 1
    int extra_one = main_sum(a, b, result, short_string_len);

    // If the two strings are of different lengths, manage the last part of the longest
    if (len_diff > 0) {
        extra_one = leftover_sum(long_string, result, len_diff, extra_one);
    }

    // Manage the extra 1, if present
    if (extra_one == 1) {
        result.push_back('1');
    }

    // Reverse the string and return
    std::reverse(result.begin(), result.end());
    return result;
}


int Solution::main_sum(const std::string& a, const std::string& b, std::string& result, int short_string_len){
        
        int extra_one = 0;

        for (int i = 0; i < short_string_len; i++) {
            
            // When we subtract '0' from a digit character,
            // the resulting value is the integer value of the digit.
            // This only works for single digits. 
            int elem_a = a[i] - '0';
            int elem_b = b[i] - '0';

            int count_of_ones = elem_a + elem_b + extra_one;

            switch (count_of_ones) {
                
                case 3:
                    result.push_back('1');
                    extra_one = 1;
                    break;
                
                case 2:
                    result.push_back('0');
                    extra_one = 1;
                    break;

                case 1:
                    result.push_back('1');
                    extra_one = 0;
                    break;

                case 0:
                    result.push_back('0');
                    extra_one = 0;
                    break;       
            }
        }

        return extra_one;
    }


int Solution::leftover_sum (const std::string& long_string, std::string& result, int len_diff, int extra_one) {
        
        for (int i = 0; i < len_diff; i++) {

                // Convert the char in integer
                int elem = long_string[len_diff + i] - '0';

                int count_of_ones = elem + extra_one;

                switch (count_of_ones) {
                
                    case 2:
                        result.push_back('0');
                        extra_one = 1;
                        break;

                    case 1:
                        result.push_back('1');
                        extra_one = 0;
                        break;

                    case 0:
                        result.push_back('0');
                        extra_one = 0;
                        break;
                }
            }

        return extra_one;
    }


std::string Solution::get_longer_string(std::string& a, std::string& b, int long_string_len) {
    
        if (long_string_len == a.size()) {
            return a;
        } else {
            return b;
        }
    }