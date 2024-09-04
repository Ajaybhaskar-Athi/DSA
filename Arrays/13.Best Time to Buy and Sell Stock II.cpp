/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 



 
// int profit(vector<int>&prices){
    //      bool min_flag=false;
    // bool max_flag=false;
    //     int buy=INT_MAX;
    //     int sell=INT_MIN;
  

    //     int profit=0;

    //     for(int i=0;i<prices.size();i++){
    //         if(!min_flag){
    //             if(prices[i]<buy)buy=prices[i];
    //             else {
    //                 min_flag=true;
    //             }
    //         }
    //         if(!max_flag){
    //             if(prices[i]>sell)sell=prices[i];
    //             else {
    //                 max_flag=true;
    //             }
    //         }
    //         if(min_flag && max_flag){
    //             profit+=sell-buy;
    //                 // helper();
    //                     min_flag=false;
    //              max_flag=false;
    //              buy=INT_MAX;
    //             sell=INT_MIN;
    //         }

    //     }
    //     return profit;


    we can do this by finding local minimum and then local maximum but this was a little confusing and bada code
    .
    And also above code is for just a bruteforce type approcah and my ABOVE code is NOT WORKING;

    REFER utube if u have still doubt
    // https://youtu.be/Q7v239y-Tik?si=zFfcf5WF_036aumV
    we have a trick for this
    sell and buy if cuurent is higher then previuos





// ******************************************************PRefixSum

    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){

            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

int BuyAndSell2(vector<int>&prices)
{   
    int n=prices.size();
    int profit=0;
    for(int i=1;i<prices.size();i++){
        int sum=prices[i]-prices[i-1];
        if(sum>0)profit+=sum;
    }
    return profit;
    


}

int main(){
          vector<int> v = {7,1,5,3,6,4};
   int profit= BuyAndSell2(v);
   cout<<profit;
}