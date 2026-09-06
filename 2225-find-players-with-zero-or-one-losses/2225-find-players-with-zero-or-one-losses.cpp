class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

      vector<vector<int>> result;  

      map<int,int> m1;
      map<int,bool> m2;

      for(int i = 0; i < matches.size(); i++){
        if(!m2.count(matches[i][0]))
            m2[matches[i][0]] = true;
        m2[matches[i][1]] = false;
        if(!m1.count(matches[i][1]))
            m1[matches[i][1]] = 1;
        else
            m1[matches[i][1]]++;     

      }
      vector<int> ans;
      for(auto p : m2){
        if(p.second == true)
            ans.push_back(p.first);
      }
      result.push_back({ans});
      ans.clear();
      for(auto p : m1){
        if(p.second == 1)
            ans.push_back(p.first);
      }
      result.push_back({ans});

return result;
    }
};