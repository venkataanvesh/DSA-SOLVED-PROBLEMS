class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        bool inComponent = false;

        while (head != nullptr) {
            if (s.count(head->val)) {
                if (!inComponent) {
                    count++;
                    inComponent = true;
                }
            } else {
                inComponent = false;
            }
            head = head->next;
        }
        return count;
    }
};
