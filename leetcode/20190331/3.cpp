#include<vector>
#include<iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> next_larger_nodes;
        do {
            ListNode* now = head->next;
            bool flag = false;
            while (now != NULL) {
                if (now->val > head->val) {
                    next_larger_nodes.push_back(now->val);
                    flag = true;
                    break;
                } else {
                    now = now->next;
                }
            }
            if (!flag) {
                next_larger_nodes.push_back(0);
            }
            head = head->next;
        } while (head != NULL);
        return next_larger_nodes;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    sol.nextLargerNodes(head);
    return 0;
}
