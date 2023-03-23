#include "../include/LengthLastWord.h"


int Solution::lengthOfLastWord(std::string& s) {

    int elem_counter = 0;
    bool flag_first_char = false;


    // It is possible to revert the string and iterate from beginning to end:
    //      std::reverse(s.begin(), s.end());
    //      for (std::string::iterator it = s.begin(); it != s.end(); it++) {}
    //
    // Alternative version of reverting the string: start from the end
    for (std::string::iterator it = s.end()-1; it != s.begin()-1; it--){

        // If it's not a blank space, start/go on counting
        if (*it != ' '){
            flag_first_char = true;
            elem_counter += 1;

        // If it is a blank space and we already encountered some non-blank char, break
        } else if (flag_first_char == true){
            break;
        }
    }

    return elem_counter;

}
