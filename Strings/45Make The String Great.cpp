Given a string s of lower and upper case English letters.

A good string is a string which doesn
t have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:

Input: s = "s"
Output: "s"






#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(c - st.top()) == 32) { // check if adjacent characters are the same but different cases
                st.pop(); // remove the last character from the stack
            } else {
                st.push(c); // add the current character to the stack
            }
        }
        
        string res = "";
        while (!st.empty()) {
            res = st.top() + res; // construct the result string in reverse order
            st.pop(); // pop the character from the stack
        }
        return res;
    }
};

***********abs gives absolute value always positive ,if its negative it converts into positive
instead of abs we can also write this thing    if (!st.empty() && ((c - st.top()) == 32 || (c - st.top()) == -32)) 


tc=O(n);

