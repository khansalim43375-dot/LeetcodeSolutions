class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        
        while(s.size() > 1){
            int firstmax = 0,idx1 = -1;
            int secmax = 0,idx2 = -1;
            for(int i = 0; i < s.size(); i++){
                if(s[i] >= firstmax){
                    secmax = firstmax;
                    idx2 = idx1;
                    firstmax = s[i];
                    idx1 = i;
                }else if(s[i] > secmax){
                    idx2 = i;
                    secmax = s[i];
                }    
            }
            if(secmax == firstmax){
                if(idx1 > idx2){
                    s.erase(s.begin()+idx1);
                    s.erase(s.begin()+idx2);
                }else{
                    s.erase(s.begin()+idx2);
                    s.erase(s.begin()+idx1);
                }   
            }else{
                s[idx1] = firstmax-secmax;
                s.erase(s.begin()+idx2);
            }
        }
    if(s.size() == 1)
       return s[0];
    return 0;       
    }
};