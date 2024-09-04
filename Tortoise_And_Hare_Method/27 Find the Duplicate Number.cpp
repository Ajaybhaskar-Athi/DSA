Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
 
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3



        method 1

        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i] ==nums[i+1])return nums[i];
        // }
        // return -1;  

    method 2

        // unordered_map<int,int>mp;

        // for(int i=0;i<nums.size();i++){
        //     int ele=nums[i];
        //     if(mp.find(ele)!=mp.end())return ele;
        //     mp[ele]++;
        // } 
        // return -1;
        method 3 OPTIMISED
        TC=o(N);
        SC=O(1);
class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        //HERE WE USE TORTOISE METHOD
        // arr=[2,5,9,6,9,3,8,9,7,1]
        // step 1-> intialisng slow and fast with 1st eleof array
        // step 2-=> moving slow by one pointer and fast by two pointers untill they intersect

        //     1->5->
        //     /     |  
        // 2->9       3
        //     |        |
        //      7<---8<-6

        // step 3-> so after this Linked list cycling slow ad fast collide at 7 index; now we move fast to 1st ele of array and slow remains there .
        //     Now we again make iterate untill slow and fast again collide to find the duplicate with both pointers move by only one time (not torotise)
        //they defintely collide since it has atleast one dup 

              int slow=nums[0];
              int fast=nums[0];
              do{
                slow=nums[slow];
                fast=nums[nums[fast]];
              } while(slow!=fast);

              fast=nums[0];
              while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
              }
              return slow; //or fast both are same

    
    }
};