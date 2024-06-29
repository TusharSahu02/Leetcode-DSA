class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*
        unordered_set<int> A(begin(nums1),end(nums1));
        unordered_set<int> B(begin(nums2),end(nums2));

        vector<int> x,y;

        for(auto i:A){
            if(B.find(i) == B.end()){
                x.push_back(i);
            }
        }

         for(auto i:B){
            if(A.find(i) == A.end()){
                y.push_back(i);
            }
        }
vector<vector<int>> ans;
ans.push_back(x);


        */

        // using STL
        // put all the unique elements from the nums1
        set<int> st1(begin(nums1), end(nums1));
        // put all the unique elements from the nums2
        set<int> st2(begin(nums2), end(nums2));

        vector<int> v1;
        vector<int> v2;
        // finding the difference in st1 and st2 and putting the unique elements
        // in v1
        set_difference(begin(st1), end(st1), begin(st2), end(st2),
                       back_inserter(v1));
        // finding the difference in st1 and st2 and putting the unique elements
        // in v2
        set_difference(begin(st2), end(st2), begin(st1), end(st1),
                       back_inserter(v2));

        return {v1, v2};
    }
};