class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        /*
                // 1st approach -> using hashmap and set

                unordered_map<int, int> mp;
                //         [number,freq]F

                // storing all the frequency of elements
                for (int &x : arr) {
                    mp[x]++;
                }

                unordered_set<int> st;

                for(auto &it : mp){
                    int freq = it.second;
                    if(st.find(freq) != st.end()){
                        return false;
                    }
                    st.insert(freq);
                }
                return true;
        */

        // 2nd approach
        // using the constraints

        vector<int> vec(2001, 0);

        for (int &x : arr) {
            vec[x + 1000]++;
        }

        sort(begin(vec), end(vec));

        for (int i = 1; i < 2001; i++) {

            if (vec[i] != 0 && vec[i] == vec[i - 1]) {
                return false;
            }
        }
        return true;
    }
};