/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
*/
#include<bits/stdc++.h>
using namespace std;


 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v(nums.size());
        for(int i=0;i<nums.size();i++){
            int p=1;
            for(int j=0;j<nums.size();j++){
            if(i!=j){
            p*=nums[j];
            }
            }
            v[i]=p;
        }
        return v;
        //tc=O(n^2);
    }};

    // but here time complexoty=O(n^2);



    // method 2

           
    // int p=1;
    //     for(int ele:nums)p*=ele;
    //     for(int i=0;i<nums.size();i++){
    //         int e=nums[i];
    //         nums[i]=(p)/e;
    //     }
    //     return nums;
    // }
    
    
    /*if we do this it give eroror because we do not handle the test cases correctly
    what is we have zeores?? divede by zero gives u error and also product p=0 we got
    so we have to rectify it

*/


#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>&v)
{

    // vector<int> v = {1, 2, 3, 4, 5, 0, 7};

        int p=1,z=0;//z=zeros p=product;
        for(int ele:v){
            if(ele==0)z++;
            else p*=ele;
        }
        if(z>1)return v;
        else if(z==1){
            for(int i=0;i<v.size();i++)v[i]=v[i]==0?p:0;
        }
        else if(z==0){
            for(int i=0;i<v.size();i++)v[i]=p/v[i];
        }

        for(int e:v)cout<<e<<" ";
        return v;



}

int main(){
          vector<int> v = {1, 2, 3, 4,0};
    productExceptSelf(v);
}



// TIME COMPLEXITY=O(n);


// we know that if k no of loops exists in an problem with independent(not neseted) then it time complexity will still O(n)  .