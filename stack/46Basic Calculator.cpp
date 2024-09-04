Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.



GIVEN ONLY -,+,(,)," " ARE in the expression
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate(string s) {
    stack<int> operands;
    int result = 0;
    int num = 0;
    int sign = 1;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Convert characters to integers and it handling multi digit numbers
            
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            operands.push(result);
            operands.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            result *= operands.top(); // Apply the sign before the parenthesis
            operands.pop();
            result += operands.top(); // Add the result before the parenthesis
            operands.pop();
        }
    }

    result += sign * num; // Add the last number
    return result + operands.top(); // Return the top element of the stack
}

int main() {
    cout << calculate("1 + 1") << endl; // Output: 2
    cout << calculate(" 2-1 + 2 ") << endl; // Output: 3
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl; // Output: 23
    return 0;
}
