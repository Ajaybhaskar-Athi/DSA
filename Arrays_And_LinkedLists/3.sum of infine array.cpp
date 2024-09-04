/*Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.

For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].

Now you are given Q queries, each query consists of two integers “L“ and “R”(1-based indexing).
 Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

Note :

The value of the sum can be very large, return the answer as modulus 10^9+7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :

Explain
1 <= T <= 100
1 <= N <= 10^4
1 <= A[i] <= 10^9
1 <= Q <= 10^4
1 <= L <= R <= 10^18

Time Limit: 1sec
Sample Input 1 :

Explain
1
3
1 2 3
2
1 3
1 5
Sample Output 1 :
6 9
Explanation to Sample Input 1 :

Explain
For the first test case, the given array A is [1,2,3] therefore the infinite array “B” will be [1,2,3,1,2,3,1,2,3,.......]. So the answer for the given first query is 6 because the sum of the subarray from index 1 to 3 of infinite array “B” i.e. (B[1]+B[2]+B[3]) is 6.

For the given second query is 9 because the sum of the subarray from index 1 to 5 of array “B” .ie (B[1]+B[2]+B[3]+B[4]+B[5]) is 9.
Sample Input 2 :

Explain
1
4
5 2 6 9
3
1 5
10 13
7 11
Sample Output 2 :
27 22 28



*/
my method :

    vector<int>
    sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q)
{
    int c;
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < q; i++)
    {
        int lower = queries[i][0];
        int high = queries[i][1];
        c = (lower % n) - 1;
        if (c < 0)
            c += n;
        for (int j = lower; j <= high; j++)
        {
            sum += arr[c++];
            if (c == n)
                c = 0;
        }
        v.push_back(sum);
        sum = 0;
    }
    return v;
}

optimised one

    we have to use long long to store sum and index values;

int mod = 1000000007;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q)
{

    // It stores answer for each query.
    vector<int> ans;

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++)
    {

        long long l = queries[i][0] - 1;
        long long r = queries[i][1] - 1;

        // It stores the sum
        long long sum = 0;

        for (long long i = l; i <= r; i++)
        {
            int index = (int)(i % n);
            sum = (sum + arr[index]) % mod;
        }
        sum %= mod; // we can omit this also

        ans.push_back((int)sum);
    }

    return ans;
}
//////////////////////////////////////
Time Complexity
O(Q*(R-L)) per test case, where Q is the number of given queries, and L and R are the given two indexes in each query.
 

In the worst case, for each query O(Q), we will be running a loop from L to R that takes (O(R-L)) time. Thus a total of O(Q*(R-L)) time will be required.
////////////////////////////////////




why we r using mod

The modulus operation (sum + arr[index]) % mod is used to prevent integer overflow and keep the result within a manageable range.

In many programming languages, integer types have a maximum value they can represent. For example,
 in C++ int typically ranges from -2,147,483,648 to 2,147,483,647 for a 32-bit signed integer. 
 If the sum of sum and arr[index] exceeds this maximum value, integer overflow occurs, and the result wraps around to a negative value or starts from the minimum value.

By taking the modulus % with respect to mod, we ensure that the result stays within a specific range. In this case, mod is 1000000007,
 which is often used in programming to perform arithmetic operations modulo this value. This value is chosen because
 its a prime number and it allows computations on very large numbers while avoiding integer overflow.

So, (sum + arr[index]) % mod ensures that the sum stays within the range 0 to mod - 1,
 preventing integer overflow and keeping the result meaningful for further computations.


/*//for a single query 
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,2,3};
    int n=v.size();
    int l=1,r=5;
    int sum=0;
    for(int ele:v)sum+=ele;
    int idx1=l%n;

    int num=(r-l+1)/n;
    int res=num*sum;
    // cout<<res<<endl;

    int idx2=(r-l+1)%n;


    while(idx1>1){
        res-=v[idx1-1];
        idx1--;
    }

    // cout<<res<<endl;

    while(idx2>0){
        res+=v[idx2-1];
        idx2--;
    }
    cout<<res<<endl;
}
*/
