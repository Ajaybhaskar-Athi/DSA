#include <iostream>
#include <vector>
using namespace std;

void printSubarraySums(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ps(n);
    ps[0] = arr[0];

    // Step 1: Build the prefix sum array
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + arr[i];
    }

    // Step 2: Calculate and print the sum of each subarray
    cout << "Sum of all subarrays:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int subarraySum = (i == 0) ? ps[j] : ps[j] - ps[i - 1];
            cout << "Subarray (" << i << ", " << j << ") sum: " << subarraySum << endl;
        }
    }
}

int main() {
    vector<int> arr = {3, 2, -1, 6, 5};
    printSubarraySums(arr);
    return 0;
}



//same time complexity as BRUTE FORCE, but it will be useful for combined questions like kth laregst subarray sum
