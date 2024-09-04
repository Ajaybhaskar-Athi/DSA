#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)return 0; //we can make all other elemnts equals to any one of elemnt . so all equal dif=0;
        sort(nums.begin(),nums.end());
        int min_diff= min({
                nums[n-1]-nums[3], //changing the Three smallest Elements ( so large will be last one and small will be 4th positon or 3rd index elment)
                nums[n-2]-nums[2],//changing two smallest and one largest
                nums[n-3]-nums[1],//changing one smallest and two largest
                nums[n-4]-nums[0]//changing the three largest elements
        });
        
        return min_diff;

    }
};



int main() {
    Solution sol;
    vector<int> nums1 = {5, 3, 2, 4};
    cout << sol.minDifference(nums1) << endl;  // Output: 0

    vector<int> nums2 = {1, 5, 0, 10, 14};
    cout << sol.minDifference(nums2) << endl;  // Output: 1

    vector<int> nums3 = {3, 100, 20};
    cout << sol.minDifference(nums3) << endl;  // Output: 0

    return 0;
}

