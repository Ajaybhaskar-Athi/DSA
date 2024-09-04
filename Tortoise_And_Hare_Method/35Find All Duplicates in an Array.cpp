// if it was finding single duplicate then we can use torotise and hare 
let array=[4,3,2,7,8,2,3,1];
its index=[0,1,2,3,4,5,6,7];

...........i=0,1,2,3,4,5,6
abs(nums[i])=4,3,2,7,8,2,3
indexToCheck=3,2,2,6,7,1,2
4,-3,-2,-7,8,2.. at this 2 we got 2-1=1 index which we seen it is already -ve means it get marked -ve only 
if the value is 2 since idx=1 so definitely before current eleemt an same eleemnt is there.


fort evry index check 
step-1: if element is positive chnage it to -ve and if ele is -ve ,add index to result set.

for evry index we will go to the index=ele-1 since they given array contains [1,n] range

// in above array , at index=2 and index=6 the element=2 so at both indexes we wiill
//got to ele-1=2-1= index 1. so at firt occur of 2 we make 3 as-ve ,so after 2nd occur when we try to
make 3 as -ve ,we observe it is already -ve .it means the current index element is repeated before. s0 we push 2 to result vector.



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i]);
            int idx=x-1;
            //since we move to psoition equal to current element 
            if(nums[idx]<0){
                res.push_back(x);
                //we have to push the absolute value not the previously marked -ve
            }
             nums[idx]*=-1;   

        }
        return res;
    }
};


tc=O(n)
sc=O(1);