#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};

class Solution {
public:
    static bool cmp(Item a, Item b) {
        // Calculating value/weight ratio
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sorting items by value/weight ratio in descending order
        sort(arr, arr + n, cmp);

        double ans = 0.0; // Use double to store fractional values

        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= w) {
                ans += arr[i].value;
                w -= arr[i].weight;
            } else {
                ans += ((double)arr[i].value / (double)arr[i].weight) * (double)w;
                break;  // Once the knapsack is full, break the loop
            }
        }

        return ans;
    }
};

