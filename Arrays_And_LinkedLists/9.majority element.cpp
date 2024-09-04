/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int maj=nums.size()/2;
        
        for(int i=0;i<nums.size()-1;i++){
            int c=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    c++;
                    if(c>maj)return nums[i];
                }
            }
        }
        return -1;
    }
};


but it has a time complexity =O(n^2);
/////////////////////////////////////////////////////////////

method 2  hashing 
BETTER Solution
 tc=O(n)
 but we r using extra space sc=O(n);
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int>mp;
    vector<int>v={1,2,1,2,1,1,1,5};
    // for(int ele:v){
      
    //   auto it=mp.find(ele);
    //   if(it==mp.end()){
    //     mp.insert({ele,1});
    //    //mp.insert(make_pair(ele,1));
    //   }
    //   else{
    //     it->second++;
    //   }
    // }
    for(int ele:v){
        mp[ele]++;
    }
    for(auto it:mp){
        if(it.second>v.size()/2){
        cout<<it.first<<" "<<it.second<<endl;
    }
    }


}

//////////////////////////////////////


method 3
tc=O(n);
sc=O(1);

// The Boyer-Moore's Majority Vote Algorithm. (Refer Geeks for geeks if u had a doubt on this method)


initially we r not intialising majority elemtt and we assume that arr[0]=major and count++.
make sure that this count is not stores how no of times major elemnt exists,its not like that .
step 1:
 we r increasing pointer if our assumed major founds we increase count otherwsise we decrease it
 step 2
 whenevr we get count=0 then we make major =current element and then again repeat step 1
 step 3
 after iteration we got major elemtn stored in major.


class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int curr=arr[0], count=0, i=0;
        int n=arr.size();

        while(i<n) {
            if(arr[i] == curr) {
                count++;
            }
            else if(count==0) {
                curr = arr[i];
            }
            else {
                count--;
            }
            i++;
        }
        return curr;
    }
};

///////////////or


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
