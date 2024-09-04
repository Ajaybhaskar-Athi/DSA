There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score.
 The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length



 Here is a more general explanation of the sliding window technique used in the provided code:

1. **Initial Window Formation**:
   - Start by calculating the sum of the first k elements of the array and assign it to the left sum (lsum).
   
2. **Expanding and Shrinking the Window**:
   - Begin with the initial window size of k elements.
   - Move the right boundary of the window towards the right of the array, incorporating a new element into the window.
   - As the window expands to the right, adjust the left and right sums accordingly.
   - Simultaneously, shrink the window by moving the left boundary towards the right while removing elements from the left.
   
3. **Updating Sums**:
   - Update the left sum (lsum) by subtracting the element that is no longer part of the window and adding the new element included in the window.
   - Update the right sum (rsum) by adding the new element as the window expands.

4. **Tracking the Maximum Sum**:
   - At each step, calculate the sum of the elements in the current window (lsum + rsum).
   - Maintain the maximum sum seen so far by comparing the previous maximum sum with the sum of the current window.

5. **Finding the Maximum Sum**:
   - Continuously update the maximum sum with the maximum value between the current maximum sum and the sum of the current window.
   
6. **Termination**:
   - Continue this process until the left boundary reaches 0, ensuring that the window moves till the end of the array.
   
7. **Final Result**:
   - Return the maximum sum found during the sliding process, which represents the maximum sum of a subarray of k elements within the array achieved by the sliding window technique.  




   class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<k;i++)lsum+=arr[i];
        maxsum=lsum;
        int ri=arr.size()-1;//right index
        for(int i=k-1;i>=0;i--){
            lsum=lsum-arr[i];
            rsum=rsum+arr[ri];
            ri--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};