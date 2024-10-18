//Geek for geeks
 /*total food we can buy in a week (6*N) is greater than or equal to total food we require to survive in a week (7*M) then we can survive. 

Note : We are buying the food in the first 6 days because we are counting from Monday and the shop will remain close on Sunday.
If any of the above conditions are not true then we can’t survive else 
Also if daily_need_units> max unit u can buy one day => then u cant survive
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
      if((6*N<7*M && S>6 ) || M>N) return -1;
      
     int total_food=S*M;
     int days=(total_food)/N;
     if(total_food%N!=0) days++;
     return days;
    }
};