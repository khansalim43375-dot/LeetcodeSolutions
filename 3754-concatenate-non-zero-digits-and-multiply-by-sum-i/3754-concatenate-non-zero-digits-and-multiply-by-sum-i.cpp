class Solution {
public:
    long long sumAndMultiply(int n) {
       string s = to_string(n);
       int i = 0,j = 0;int sum = 0;
       while(j < s.length()){

        if(s[j] != '0' ){
            s[i] = s[j];
            i++;
        }
       j++;  
       } 
       s = s.substr(0,i);
       if(s.empty())
          return 0;
       for(int i = 0; i < s.length(); i++){
        int dig = s[i] - '0';
        sum += dig;
       }

    return 1LL*sum*stoi(s);
    }
};