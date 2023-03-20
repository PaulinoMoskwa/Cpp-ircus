#ifndef BINARY_SUM_H
#define BINARY_SUM_H

#include <string>


class Solution {
    
    public:
        std::string addBinary(std::string a, std::string b);

    private:
        int main_sum(
            const std::string& a,
            const std::string& b,
            std::string& result,
            int short_string_len
        );
        
        int leftover_sum (
            const std::string& long_string,
            std::string& result,
            int short_string_len,
            int len_diff,
            int extra_one
        );
        
        std::string get_longer_string(
            std::string& a,
            std::string& b,
            int long_string_len
        );
};


#endif // BINARY_SUM_H
