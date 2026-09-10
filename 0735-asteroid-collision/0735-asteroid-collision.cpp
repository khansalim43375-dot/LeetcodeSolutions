class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int x : asteroids) {

            bool alive = true;

            while (alive && x < 0 && !st.empty() && st.back() > 0) {

                if (st.back() < abs(x)) {
                    st.pop_back();       // stack asteroid explodes
                }
                else if (st.back() == abs(x)) {
                    st.pop_back();       // both explode
                    alive = false;
                }
                else {
                    alive = false;      // current asteroid explodes
                }
            }

            if (alive)
                st.push_back(x);
        }

        return st;
    }
};