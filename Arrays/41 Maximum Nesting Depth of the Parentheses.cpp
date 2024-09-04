// A string is a valid parentheses string (denoted VPS) if it meets one of the following:

// It is an empty string "", or a single character not equal to "(" or ")",
// It can be written as AB (A concatenated with B), where A and B are VPSs, or
// It can be written as (A), where A is a VPS.
// We can similarly define the nesting depth depth(S) of any VPS S as follows:

// depth("") = 0
// depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
// depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
// depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
// For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

// Given a VPS represented as string s, return the nesting depth of s.

 

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.
// Example 2:

// Input: s = "(1)+((2))+(((3)))"
// Output: 3
 

// Constraints
// ""



 To find the nesting depth of the parentheses in a given VPS string, we can iteratively scan and count the opening and closing parentheses. Here's a simple algorithm to calculate the nesting depth of parentheses:

1. Initialize two variables: `max_depth` to track the maximum depth encountered so far, and `current_depth` to track the current depth.
2. Iterate over each character in the input string `s`.
3. If the character is an opening parenthesis '(', increment `current_depth` by 1.
4. Update `max_depth` if `current_depth` is greater than `max_depth`.
5. If the character is a closing parenthesis ')', decrement `current_depth` by 1.
6. Repeat steps 3-5 until the end of the string is reached.
7. The final `max_depth` value will be the nesting depth of the given VPS string `s`.

This algorithm effectively keeps track of the current nesting depth as we traverse the string character by character, updating the maximum depth encountered whenever needed.  



class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_num = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                if (max_num < count)
                    max_num = count;
            } else if (c == ')') {
                count--;
            }
        }
        return max_num;
    }
};