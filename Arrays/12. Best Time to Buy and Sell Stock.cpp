/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
 */
// wrong method
//     class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min_idx=0;
//         // int min=prices[0];
//         for(int i=1;i<prices.size();i++){
//             if(prices[i]<prices[min_idx])min_idx=i;
//         }
//         if(min_idx==prices.size()-1)return 0;
//         int max_idx=min_idx;//let taking same index
//         for(int i=min_idx;i<prices.size();i++){
//             if(prices[i]>prices[max_idx])max_idx=i;
//         }
//         return prices[max_idx]-prices[min_idx];

//     }
// };

suppose if we do like above like we find small first and then heighest and subtracting it will be a blunder mistake

lets seee
[2,4,1] with above method lowest buting day price=1 and after 1 no elemnts there so we put profit =0
but when we observe we can buy at 2 and sold at 4 we get profit =2*************************
so above is wrong


 #include <bits/stdc++.h>
using namespace std;

vector<int> BuyAndSell(vector<int>&prices)
{   
    int n=prices.size();
    int profit =0;
    int min_price=prices[0];
    for(int i=1;i<n;i++){
        if(prices[i]<min_price)min_price=prices[i];
        else profit=max(profit,prices[i]-min_price);
    }
    cout<<profit<<endl;
    


}

int main(){
          vector<int> v = {7,1,5,3,6,4};
    BuyAndSell(v);
}

tc=O(n);