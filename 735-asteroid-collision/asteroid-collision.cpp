class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i : asteroids) {

            bool destroyed = false;

            // Collision is possible only when:
            // stack top is moving right and current asteroid is moving left
            while (!st.empty() && st.top() > 0 && i < 0) {

                if (abs(st.top()) < abs(i)) {
                    // Top asteroid gets destroyed
                    st.pop();
                }
                else if (abs(st.top()) == abs(i)) {
                    // Both get destroyed
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid gets destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(i);
            }
        }

        vector<int> result(st.size());

        for (int j = st.size() - 1; j >= 0; j--) {
            result[j] = st.top();
            st.pop();
        }

        return result;
    }
};