class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size(); 
        int count1 = 0;
        int one=0;
        int minSwap = n;
        int i=0, j=0;

        // total count of 1's in array
        for(int i: nums){
            if(i == 1){
                count1++;
            }
        }

        // append the vector as it is for circular array
        nums.insert(nums.end(),nums.begin(),nums.end());


        while(j<2*n){
            // total no. of 1's in window
            one += (nums[j] == 1);

            // checking if the total no of 1's if covered
            if(j-i+1 == count1){
                minSwap =  min(minSwap,count1-one);
                one -= (nums[i] == 1);
                i++;
            }
            j++;
        }

        return (minSwap == n ? 0 : minSwap);    
        
    }
};
