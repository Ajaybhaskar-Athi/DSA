#include <bits/stdc++.h>
using namespace std;
//lowerBound= samllest Index sunch that arr[index]>=x

int lowerBound(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // intially no element greatr then equals x;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
    // STL template
    // return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    //we r subtracting from starting iterator since with lower_bound function we got that lowerbound index ka iterator. subtract both to get the index 

}

//upper_Bound= samllest Index sunch that arr[index]>x


int upperrBound(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size(); // intially no element greatr then equals x;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >x)//thats it ntg else
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
        // return upper_bound(nums.begin(),nums.end(),x)-nums.begin();
}
int main()
{
    vector<int> v = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    cout<<lowerBound(v,9);
    cout << lower_bound(v.begin(), v.end(), 9)-v.begin();
}
