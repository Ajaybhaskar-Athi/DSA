#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
    void print(ListNode*head){
        ListNode*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // after this iteration slow points at midpoint
        }
        // first half;
        ListNode* fh = head;
        print(fh);
        print(slow);
        // second half
        ListNode* sh = rev(slow);
        print(sh);
    
        while (fh && sh) {
            if (fh->val != sh->val) return false;
            fh = fh->next;
            sh = sh->next;
        }
        return true;
    }
};

int main() {
    // Creating a linked list: 1 -> 1 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    std::cout << "Is Palindrome: " << std::boolalpha << solution.isPalindrome(head) << std::endl;

    // Freeing memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
