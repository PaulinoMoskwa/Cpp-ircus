#include "../include/RemoveElement.h"


void Solution::removeElement(std::vector<int>& nums, int val) {
    
    // Go through the vector with an iterator
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end();) {

        // If `val` encountered, delete it
        if (*it == val) {
            nums.erase(it);

        // Otherwise, go on
        } else {
            it++;
        }
    }
}
