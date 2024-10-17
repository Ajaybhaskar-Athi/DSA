#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
To minimize the total cash flow among a group of friends based on their transactions, we need to understand the concept of net debt. The idea is that each friend either owes or is owed a certain amount, and we aim to reduce the number of transactions while maintaining the correct balance of debts.

Here's how the algorithm works:

Algorithm Steps:
Calculate Net Balance: For each person, calculate the net balance by subtracting the amount they owe from the amount they are owed. This balance tells us whether a person is a debtor (negative balance) or a creditor (positive balance).

Settle Transactions:

Try to settle debts in such a way that minimizes the number of transactions.
The maximum creditor (person who is owed the most) and maximum debtor (person who owes the most) should settle their debt first.
Recursively settle the remaining debts.


Explanation:
getMaxCredit: This function finds the person who has the maximum positive balance (i.e., they are owed the most).
getMaxDebit: This function finds the person who has the maximum negative balance (i.e., they owe the most).
settleDebts: This function recursively settles the debts by allowing the person with the maximum debit to pay the person with the maximum credit, minimizing the total number of transactions.

*/



class Solution {
public:
    // Function to get the index of the person with maximum credit
    int getMaxCredit(const vector<int>& balance) {
        return max_element(balance.begin(), balance.end()) - balance.begin();
    }

    // Function to get the index of the person with maximum debit
    int getMaxDebit(const vector<int>& balance) {
        return min_element(balance.begin(), balance.end()) - balance.begin();
    }

    // Function to settle debts recursively
    void settleDebts(vector<int>& balance, vector<vector<int>>& transaction) {
        int maxCredit = getMaxCredit(balance);
        int maxDebit = getMaxDebit(balance);

        // If all balances are 0, we are done
        if (balance[maxCredit] == 0 && balance[maxDebit] == 0) {
            return;
        }

        // Find the minimum value to transfer
        int amount = min(balance[maxCredit], -balance[maxDebit]);

        // Settle the amount between the max debtor and max creditor
        balance[maxCredit] -= amount;
        balance[maxDebit] += amount;

        // Record the transaction in the transaction matrix
        transaction[maxDebit][maxCredit] += amount;

        // Recursively settle the rest of the debts
        settleDebts(balance, transaction);
    }

    // Function to minimize cash flow among friends
    vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n) {
        vector<int> balance(n, 0);

        // Calculate net balance for each person
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                balance[i] += (transaction[j][i] - transaction[i][j]);
            }
        }

        // Clear the original transaction matrix for the minimized cash flow result
        vector<vector<int>> newTransaction(n, vector<int>(n, 0));

        // Settle debts and store the result in the newTransaction matrix
        settleDebts(balance, newTransaction);

        // Return the minimized transaction matrix
        return newTransaction;
    }
};

