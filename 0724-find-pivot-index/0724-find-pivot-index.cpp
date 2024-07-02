class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /* 1st approach : */
        // let's do dry run with array of [1,7,3,6,5,6]
        vector<int> pre(nums.size(), 0); // [0,0,0,0,0,0]
        int sum = nums[0]; // sum = 1

        for (int i = 1; i < nums.size(); i++) { 
            sum += nums[i];
            // i = 1 -> sum = 1 + 7 = 8 
            // i = 2 -> sum = 8 + 3 = 11
            // i = 3 -> sum = 11 + 6 = 17
            // i = 4 -> sum = 17 + 5 = 22
            // i = 5 -> sum = 22 + 6 = 28 
            pre[i] = pre[i - 1] + nums[i - 1];
            // i = 1 ->  pre[1] = pre[0] + nums[0] = 0 + 1 = 1
            // i = 2 ->  pre[2] = pre[1] + nums[1] = 1 + 7 = 8
            // i = 3 ->  pre[3] = pre[2] + nums[2] = 8 + 3 = 11
            // i = 4 ->  pre[4] = pre[3] + nums[3] = 11 + 6 = 17
            // i = 5 ->  pre[5] = pre[4] + nums[4] = 17 + 5 = 22
        }
        // sum = 27
        for (int i = 0; i < nums.size(); i++) {
            /*
             i = 0 -> 0 != 28 - 1 - 0 
             i = 1 -> 1 != 28 - 7 - 1
             i = 2 -> 8 != 28 - 3 - 8
             i = 3 -> 11 == 28 - 6 - 11 - (pivot index)
             i = 4 -> 17 != 28 - 5 - 17
             i = 5 -> 22 !=  28 - 6 - 22
            */ 
            if (pre[i] == sum - nums[i] - pre[i]) {
                // so return 3
                return i;
            }
        }
        return -1;
    }
};