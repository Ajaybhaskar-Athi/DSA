#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int ele : bills) {
            if (ele == 5) {
                five++;
            } else if (ele == 10) {
                if (five > 0) {
                    ten++;
                    five--;
                } else {
                    return false;
                }
            } else if (ele == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

