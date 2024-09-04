You are given an integer array 'ARR' of size 'N' and an integer 'S'.
Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:


Explain
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value,
 the pair with a smaller second value should come first.
Detailed explanation ( Input/output format, Notes, Images )

Explain
Constraints:

Explain
1 <= N <= 10^3
-10^5 <= ARR[i] <= 10^5
-2 * 10^5 <= S <= 2 * 10^5

Time Limit: 1 sec
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2


Hints:
As N is relatively small, an O(N^2) solution may pass.



#include <vector>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> v;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                v.push_back({arr[i], arr[j]});
            }
        }
    }
    return v;
}


but with aboive method we got output but not according to testcases .
if we observe we got to know that they given according to ascending order with each elemtn min at first and max at last

#include <vector>
#include <algorithm> // for std::sort
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> v;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                v.push_back({arr[i], arr[j]});
            }
        }
    }

vector<vector<int>>res(v.size(),vector<int>(2,0));
for(int i=0;i<v.size();i++){
   int a=v[i][0];
   int b=v[i][1];
   res[i][0]=min(a,b);
   res[i][1]=max(a,b);

}
sort(res.begin(),res.end());
    return res;
}


we can also push the elemsnt slike below
/*

    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the size of the array.
    


vector< vector<int> > pairSum(vector<int> &arr, int s){
    int n = arr.size();
    // Used to store result.
    vector< vector<int> > ans;
        
    // Checking sum for every element.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[j];
                ans.push_back(pair);
            }
        }
    }

    // Used to store final sorted result.
    vector<vector<int> > res(ans.size(),vector<int>(2,0));
    for(int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];

        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }
    sort(res.begin(),res.end());  
    return res;
}
*/