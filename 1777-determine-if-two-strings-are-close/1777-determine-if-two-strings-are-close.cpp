class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // size of word1 and word2
        int n = word1.length();
        int m = word2.length();

        // return false if the size does not match
        // which means we cannot further operation
        if (n != m) {
            return false;
        }
        // init 2 vector to store the freq of both word1 and word2 chars;
        vector<int> v1(26);
        vector<int> v2(26);

        // iterate in string and update the freq and store them into vector v1
        // and v2
        for (int i = 0; i < n; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];

            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';

            v1[idx1]++;
            v2[idx2]++;
        }

        // check that jo char word1 me hai woh word2 me bhi hona chahiye
        for (int i = 0; i < 26; i++) {
            if (v1[i] != 0 && v2[i] != 0) {
                continue;
            }
            if (v1[i] == 0 && v2[i] == 0) {
                continue;
            }

            return false;
        }
        // sort both the vector and match the freq.
        // if yes -> true else will return false;
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));

        return v1 == v2;
    }
};