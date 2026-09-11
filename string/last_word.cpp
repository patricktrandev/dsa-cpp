#include <iostream>
using namespace std;


int lengthOfLastWord(string s) {
    int i=s.length()-1; int space=0; int count=0; 
    while(i>=0){
        
        if(s[i]!=' ' ){
            count++;
        }else if (s[i]==' ' && count==0){
            space++;
        }else{
            break;
        }

        i--;
    }
    return count;
}
int main() 
{
    /**
 * @file main.cpp
 * @brief Solution for LeetCode 58: Length of Last Word.
 */

/**
 * @brief Calculates the length of the last word in a given string.
 *
 * This function traverses the input string backwards starting from the last character:
 * 1. Ignores trailing space characters while no word characters have been counted yet.
 * 2. Increments the word length counter upon encountering non-space characters.
 * 3. Terminates traversal immediately when a space is hit after counting characters.
 *
 * @param s The input string containing words separated by spaces.
 * @return int The length of the last word in string `s`.
 *
 * @note Time Complexity: O(N) where N is string length (scans at most N characters).
 * @note Space Complexity: O(1) auxiliary space (in-place scan without memory allocation).
 */
    string s;
    getline(cin, s);
    cin.ignore();
    int i=lengthOfLastWord(s);
    cout<<i;
    return 0;
}