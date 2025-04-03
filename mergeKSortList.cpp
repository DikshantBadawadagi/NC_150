/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }

        if (h1 != nullptr) temp->next = h1;
        if (h2 != nullptr) temp->next = h2;

        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int n = lists.size();
        while (n > 1) {
            int j = 0;
            for (int i = 0; i < n - 1; i += 2) {
                lists[j++] = merge(lists[i], lists[i + 1]);
            }
            if (n % 2 == 1) lists[j++] = lists[n - 1];
            n = j; 
        }
        return lists[0];
    }
};
