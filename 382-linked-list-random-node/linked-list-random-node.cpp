class Solution {
private:
    vector<int> arr;

public:
    Solution(ListNode* head) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int idx = rand() % arr.size();  // Generate a random index
        return arr[idx];
    }
};