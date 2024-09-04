











Every single digit is a palindrome! 🎉

0 is a palindrome because it reads the same forwards and backwards.
1 is also a palindrome for the same reason.
And even 9 qualifies as a palindrome.

************** negative numbers are not palindromes
**-9** is not a palindrome.
 Unlike the single-digit palindromes (such as 0, 1, and 9),
  **-9** does not read the same forwards and backwards. 


  *************
  Why Multiples of 10 Are Not Palindromes:
Consider the number 10. If we reverse it, we get 01, which is not the same as 10.
The same applies to all multiples of 10. Reversing them results in a trailing zero, which makes them different from the original number.


method 1:
revrse the entire and compare


  // if(x<0 ||(x%10==0 && x!=0)) return false;
        // int rev=0;
        // int temp=x;
        // while(temp!=0){
        //     int digit=temp%10;
        //     rev=rev*10+digit;
        //     temp/=10;
        // }
        // return (rev==x);

methiod 2
reverse the second half and comapre it with first half



class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0 ||(x%10==0 && x!=0)) return false;
            int rev=0;
            while(x>rev){
                rev=rev*10+x%10;
                x/=10;
            }
            //handling the even and odd length cases 
            return x==rev ||x==rev/10;
    }
};

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();