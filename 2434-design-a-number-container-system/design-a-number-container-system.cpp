#include <iostream>
#include <map>
#include <set>

class NumberContainers {
public:
    map<int, int> indexToNumber;          // Maps index to number
    map<int, set<int>> numberToIndices; 
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }

        // Update indexToNumber with the new number
        indexToNumber[index] = number;
        
        // Add the index to the set of indices for the new number
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
         // Check if there are indices for the given number
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();  // Return the smallest index
        }
        return -1;  // If no index found, return -1
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */