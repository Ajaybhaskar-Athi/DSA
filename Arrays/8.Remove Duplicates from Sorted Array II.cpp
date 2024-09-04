/*Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 */

#include<bits/stdc++.h>
using namespace std;



 class Solution {
public:
    int removeDuplicatesII(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int j=2;
        for(int i=2;i<nums.size();i++){
         if(nums[i]!=nums[j-2]){
            nums[j++]=nums[i];
        }
        }
        return j;
        
    }
};



u may have a confusion why we use j-2 instead of i-2 .since if we use i-2  it checks with the element in new array/so  it may be a chance that
we comapre with wrong element.

suppose 1,1,1,2,2,3
so when we compare with second occurance of 2 our new array is 1,1,2,..
so we get i-2=4-2=2 so it compare arr[i]!=arr[i-2]=> 2!=2 here arr[i-2] not take  original array value it takes recent array value which is 2
so it false and second occurance of 2 is not addes
hence we check with arr[i]!=arr[j-2]=>>  arr[4]!=arr[3-2] (since at that time j=3 unique elemtns) 
 so we get 2!=1 yes its true so second 2 is added.

so