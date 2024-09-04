TWO POINTER APPROACH 

    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.



class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(')open.push(i);
            else if(ch=='*')star.push(i);
            else{
                if(open.empty() &&star.empty())return false;
                else if(!open.empty())open.pop();
                else{
                    star.pop();
                }
            }
        }
        while(!open.empty()){
            if(star.empty())return false;
            if(open.top()>star.top())return false;
            open.pop();
            star.pop();
        }
        return true;
    }
};


tc=O(n) and sc=o(n);




TWO POINTER APPROACH



We can utilize a two-pointer greedy approach, examining the balance between open and closed brackets from both ends of the array simultaneously.
Starting from the left, we traverse the array, counting occurrences of open brackets '(' and asterisks ''. Whenever we encounter a closed bracket ')',
 we decrement the count of open brackets. Simultaneously, we traverse from the right, counting occurrences of closed brackets ')' and asterisks ''. 
 Whenever we encounter an open bracket '(', we decrement the count of closed brackets.
If either the count of open brackets or closed brackets becomes negative during this process,
 it indicates an imbalance in the sequence, leading to an immediate conclusion of invalidity.
If neither counter becomes negative throughout the iteration, the sequence is considered valid, and we return true.

 This approach efficiently checks bracket balance without relying on additional data structures.




class Solution
{
public:
    bool checkValidString(string s)
    {
        int leftBalance = 0, rightBalance = 0;
        int n = s.size(); // Length of the string
        // First pass: check from left to right treating asterisks as open brackets
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*') // Increment left balance for open brackets and asterisks
                leftBalance++;
            else // Decrement left balance for close brackets
                leftBalance--;

            // Perform the same operations for the corresponding character from the right end of the string
            if (s[n - 1 - i] == ')' || s[n - 1 - i] == '*')
                rightBalance++;
            else
                rightBalance--;

            // More right brackets than left brackets and asterisks OR  More left brackets than right brackets and asterisks
            if (leftBalance < 0 || rightBalance < 0)
                return false;
        }
        return true; // If the balance remains non-negative throughout the string, it's valid
    }
};



sc=o(1) and tc=o(n)
