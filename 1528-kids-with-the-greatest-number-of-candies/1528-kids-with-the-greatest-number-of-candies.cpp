class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // count to track the incremented number
        int count = 0;
        // to store all bool values
        vector <bool> isGreat;
        // to compare between the incremented number and max in array
        int max = INT_MIN;

        for(int i=0;i<candies.size();i++){
            // iterating in array and updating the max value
            if(candies[i] > max) {
                max = candies[i];
            }
        }

        for(int i=0;i<candies.size();i++){
            // iterating in array and incrementing the values by extraCandies
            count = extraCandies + candies[i];
            // checking if the count is greater than max then send true to isGreat vector
            if(count >= max) {
                isGreat.push_back(true);
            }else{ // else send false to isGreate vector
                isGreat.push_back(false);
            }
        }
        return isGreat;
    }
};