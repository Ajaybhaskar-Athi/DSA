 Contiguous Array

 Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.





class Solution {
public:
contiguos array means a subarray which continas equla no of 1's and 0's
//     lets take an array=1,1,0,0,1,1,0,1,1; given it only contains 0 & 1 .its subarray length=6

//     here we observe that if we take 0=-1 then the contiguos subarray sum=0
//     so we are doing sum by iterating entire array.if 1 add 1 ,if 0 subtract -1

//     ********8so whenever we get sum=0 means from start to current index the subarray is contigus => subarray length= 0th index to curr= curr+1; since index starts from 0

// also while calculating sum if sums are repeating means from prev reeated sum index to curr index its sum=0 and it is  contiguso. 
// ex: sum of above array=1,2,3,2,1,2,3;
// here at 4th pos we get which is prev presnet at 2nd pos .so from 2nd pos to 4th pos sum=0 and array is contiguos.

// ******so in map when we get sum which is laready find in the map ,we find max b/w  prevoius subarray length and current sub array length 
// ******* if these two not happende we simply add these NEW element into map
// https://youtu.be/9ZyLjjk536U?si=XvZLWv267LFYaTEc

    int findMaxLength(vector<int>& nums) {
      unordered_map<int,int>mp;
      int sum=0;
      int subArr_length=0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i]==0?-1:1;
        if(sum==0){
            subArr_length=i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            subArr_length=max(subArr_length,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
       
    }
      return subArr_length;}
     

    
};