#include<bits/stdc++.h>
using namespace std;


class solution {
public:
    // Comparator function to sort by ending times
    static bool cpp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sort by the ending time in ascending order
    }

    void maxMeetings(vector<int>& s, vector<int>& e) {
        vector<vector<int>> v2(s.size(), vector<int>(2));
        for (int i = 0; i < s.size(); i++) {
            v2[i][0] = s[i]; // Start time
            v2[i][1] = e[i]; // End time
        }
        


        sort(v2.begin(), v2.end(), cpp); 

        // Print the sorted matrix
        cout << "Sorted meetings (start time, end time):" << endl;
        for (const auto& meeting : v2) {
            cout << "(" << meeting[0] << ", " << meeting[1] << ") ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> s = {0, 3, 1, 5, 5, 8};
    vector<int> e = {5, 4, 2, 9, 7, 9};
    solution obj;
    obj.maxMeetings(s, e);
    return 0;
}
