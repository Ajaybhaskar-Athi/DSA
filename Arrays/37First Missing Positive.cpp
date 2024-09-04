Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp; // Map to mark the presence of numbers
        
        // Mark elements from nums
        for (int num : nums) {
            if (num > 0 && num <= n) {
                mp[num] = true;
            }
        }
        
        // Iterate from 1 to n
        for (int i = 1; i <= n; i++) {
            // If i is not found in the map, return it as missing positive
            if (mp.find(i) == mp.end())
                return i;
        }
        
        // If all numbers from 1 to n are found, return n+1
        return n + 1;
    }
};

by using hash map time complexity = O(N) that good  but space complexity= o(n);


METHIOD 2
swaping to the correct positions
suppose n=6;
we need to swap the array to the respective positions such that we can check 
********  [1,2,3,4,5,6];
 indexes= [0,1,2,3,4,5]; this is the array we need to check with the our given array for n=6

suppose our array=[3,2,1,-3,8,2]
step 1) elee=3 and its chair = 3-1=2 so we swap with index 2 and curr ele(3);
        and i=still 0; since we need to check whether swapped one is at its current pos or not
        new arr=[1,2,3,-3,8,2]
step 2) ele=1 its chair=1-1=0 YES it is at correct pos so i++
step 3) ele=2 its chair=2-1=1 so 2 should be at chair 1 .YES its already there so i++
 similary now ele=3 index/chair=3-1=2 YES so i++
 step 4) ele=-3 we didint allocate or check for chair allocatiion for elements <1 and >n s
 since we need to find smallest missing positive so we r searching and swaping to their correct positions and no need of other
 so i++;
 step 5)ele =8 > n=6 so i++;
 step 6) ele=2 chair=2-1=1 so nums[1]==ele => 2===2 yes 2 is already present so i++;


 now overall new array= [1,2,3,-3,8,2]
now check with [1,2,3,4,5,6] andd return whenever this arr elemtn was not at its correect pos i new array and return that 
if all are at correct pos then return n+1;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ele=nums[i];
            if(ele>=1 && ele<=n){
                
            int chair=ele-1;
                if(nums[chair]!=ele){
                    swap(nums[chair],nums[i]);
                    i--;
                    //we have to check the swapped elemtn also if it was not at correct position
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])return i+1;
        }
        return n+1;
    }
};


TC=O(n);
sc=O(1);