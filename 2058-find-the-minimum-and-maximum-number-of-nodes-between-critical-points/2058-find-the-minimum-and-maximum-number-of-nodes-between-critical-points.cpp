class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int i = 1;

        while(next != NULL) {

            if((curr->val > prev->val && curr->val > next->val) ||
               (curr->val < prev->val && curr->val < next->val)) {
                ans.push_back(i);
            }

            i++;
            prev = curr;
            curr = next;
            next = curr->next;
        }

        if(ans.size() < 2)
            return {-1, -1};

        int mn = INT_MAX;

        for(int i = 1; i < ans.size(); i++) {
            mn = min(mn, ans[i] - ans[i-1]);
        }

        int mx = ans.back() - ans.front();

        return {mn, mx};
    }
};