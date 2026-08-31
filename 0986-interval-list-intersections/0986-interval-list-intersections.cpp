class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        
        vector<vector<int>> result;
        int i = 0, j = 0;

        while(i < l1.size() && j < l2.size()) {

            int start = max(l1[i][0], l2[j][0]);
            int end = min(l1[i][1], l2[j][1]);

            if(start <= end) {
                result.push_back({start, end});
            }

            if(l1[i][1] < l2[j][1])
                i++;
            else
                j++;
        }

        return result;
    }
};