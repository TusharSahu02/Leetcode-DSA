class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxVal = 0;

        for(auto val : gain){
            alt += val;
            maxVal = max(alt,maxVal);
        }
        return maxVal;
    }
};