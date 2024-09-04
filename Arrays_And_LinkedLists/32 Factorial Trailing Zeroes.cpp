Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0


The goal is to find the number of trailing zeroes in the factorial of a given number n.
Trailing zeroes occur when there are pairs of 2 and 5 in the factorial.
Since there are usually more 2s than 5s in the factorial, we focus on counting the number of 5s.

= [n/5] + [n/5^2] + [n/5^3] + [n/5^4]+…………
=n/5 + (n/5)/5 + ((n/5)/5)/5 + (((n/5)/5)/5)/5 + …



Time complexity:
O(log n)

Space complexity:
O(1)

ex: n=100
100/5=20/5=4/5
add above numerators except 100 we get 24 zeores in 100!


class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        while (n >= 5) {
            zeros += n / 5;
            n /= 5;
        }
        return zeros;
    }
};