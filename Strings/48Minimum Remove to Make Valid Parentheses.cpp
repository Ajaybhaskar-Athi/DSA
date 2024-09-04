Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.




EXPLANTION
In simpler terms, a valid parentheses string must have matching pairs of parentheses. For every '(' character, there must be a corresponding ')' character.

Here's how you can approach this problem:

Initialize a stack to keep track of the indices of '(' characters in the string.
Iterate through the string:
If you encounter a '(', push its index onto the stack.
If you encounter a ')':
If the stack is not empty, pop an index from the stack (indicating a matching '(' character).
If the stack is empty, it means there is a ')' without a matching '('. In this case, mark the current ')' character for removal.




class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>stk;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(')stk.push(i);
            else if(ch==')'){
                if(stk.empty() || s[stk.top()]==')')stk.push(i);
                else if(s[stk.top()]=='(') stk.pop();
            }
        }
        string res="";
        vector<bool>v(s.size(),true);
        while(!stk.empty())
{
    v[stk.top()]=false;
    stk.pop();
}       
        for(int i=0;i<s.size();i++){
            if(v[i])res+=s[i];
        }
        return res;

    }

};




ALSO WE CAN DOW BELEOW ONE BOTH ARE HAVING SAME TIME COMPPLEXITIES O(N)


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Initialize variables
        int openParenthesesCount = 0;
        vector<char> arr(s.begin(), s.end()); // Convert string to character array

        // First pass: mark excess closing parentheses with '*'
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                openParenthesesCount++;
            else if (arr[i] == ')') {
                if (openParenthesesCount == 0)
                    arr[i] = '*'; // Mark excess closing parentheses
                else
                    openParenthesesCount--;
            }
        }

        // Second pass: mark excess opening parentheses from the end
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (openParenthesesCount > 0 && arr[i] == '(') {
                arr[i] = '*'; // Mark excess opening parentheses
                openParenthesesCount--;
            }
        }
        
        // Filter out marked characters and store the result in a new string
        string result = "";
        for (char c : arr) {
            if (c != '*')
                result += c;
        }

        return result;
    }
};