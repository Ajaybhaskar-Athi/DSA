/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length*/



/*

given that in a farm there are types of frutis like apples,manogoes (in questio it give in numbers). 
and we have two baskets, and each basket holds only single type of fruit that can contain many no of fruits of that type.

return the the maximum no of fruits u can hold in two baskets. 
The fruits are from ordered only i.e,, from left to right in adjacent only 
*/




/*
Simply find the max length sub array with atmost 2 types of numbers .

*/
#include<bits/stdc++.h>
using namespace std;


//BRUTFORCE

int brutforce(vector<int>&v){
    int n=v.size();
    int len=0;
for(int i=0;i<n;i++){
    set<int>s; //that stores unique lements only
    for(int j=i;j<n;j++){
        s.insert(v[j]);
        if(s.size()<=2)len=max(len,j-i+1);
        else break;
        
    }
    return len;
}
}



//SLiding window

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,len=0;
        int n=fruits.size();
        map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
           while(mp.size()>2){
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0)mp.erase(fruits[i]); // if count ==0 then remove it from map;
            i++;
           }
             len=max(len,j-i+1);
             j++;
        }
        return len;
       
    }
};