#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;

bool isValid(string s){
    int i =0;
    set<char> pa={'(','[','{'};
    stack<char> p; 
    if(s.size()<2) return false;
    while(s[i]!='\0'){
        if(pa.find(s[i]) != pa.end()){
            p.push(s[i]);
        }else{
            //check stack empty
            if (p.empty()) return false; 
            char t= p.top();
            if((t == '{' && s[i]=='}')  || ((t == '(' && s[i]==')')  || (t == '[' && s[i]==']'))){
                p.pop();
            }else{
                return false;
            }
        }
        i++;
    }
    if(p.size() > 0){
        return false;
    }
    return true;
    
}

int main(){
    /** LEETCODE 20
     * VALID PARENTHESES
     *
     * @brief Determines if the input string of parentheses is valid.
     *
     * The algorithm traverses the string from left to right using a Stack data structure.
     * It uses a `std::set` to quickly identify opening brackets.
     *
     * - If the current character is an opening bracket ('(', '[', '{'), it is pushed onto the stack.
     * - If it is a closing bracket (')', ']', '}'), the algorithm checks the top of the stack:
     *   - If the stack is empty or the top bracket does not match the current closing bracket, the string is invalid.
     *   - If it matches, the opening bracket is popped from the stack.
     * - After processing the entire string, the stack must be empty for the string to be valid.
     *
     * Input Sample:
     *
     *   s = "([ text ])"  (Note: non-bracket characters are treated as closing bracket failures in this specific logic)
     *   Standard Sample: s = "([])"
     *
     * Execution Step-by-Step (Left-to-Right Traversal for "([])"):
     *
     *   Step 1: Char '(' -> Is opening bracket -> p.push('(')                  (Stack: ['('])
     *   Step 2: Char '[' -> Is opening bracket -> p.push('[')                  (Stack: ['(', '['])
     *   Step 3: Char ']' -> Is closing bracket -> p.top() is '[' (Match!) -> p.pop() (Stack: ['('])
     *   Step 4: Char ')' -> Is closing bracket -> p.top() is '(' (Match!) -> p.pop() (Stack: [])
     *   Step 5: Loop ends -> p.size() == 0                                     -> Returns true
     *
     * Execution Step-by-Step (Left-to-Right Traversal for "(("):
     * 
     *   Step 1: Char '(' -> Is opening bracket -> p.push('(')                  (Stack: ['('])
     *   Step 2: Char '(' -> Is opening bracket -> p.push('(')                  (Stack: ['(', '('])
     *   Step 3: Loop ends -> p.size() > 0 (Dangling open brackets)             -> Returns false
     *
     * Purpose:
     * Demonstrates how to:
     * - Use a Stack (LIFO) to ensure brackets are closed in the correct, nested order.
     * - Use `std::set` for O(log N) lookup to classify character types.
     * - Validate boundary conditions (e.g., preventing underflow via `p.empty()` check).
     *
     * Time Complexity: O(N log K) where K is the size of the set (K=3, so effectively O(N)).
     * Space Complexity: O(N) in the worst case where all characters are opening brackets.
     *
     * where N is the length of the string `s`.
     */
    string s;
    getline(cin, s);
    bool isValidParentheses=isValid(s);
    isValidParentheses ? cout<<"true": cout<<"false"; 

  return 0;
}