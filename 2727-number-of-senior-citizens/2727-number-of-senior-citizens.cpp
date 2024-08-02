class Solution {
public:
    int countSeniors(vector<string>& details) {
        int snrCitizan =0;
        for(const string& info : details){
            char tens = info[11];
            char ones = info[12];

            if(tens > '6' || (tens == '6' && ones > '0')){
                snrCitizan++;
            }
        }
        return snrCitizan;

        /*
        using STL functions

        int ans =0;
        for(auto &x : details){
            int age = stoi(x.substr(11,2));
            ans += (age > 60);
        }

        return ans;     
        
        */
        






    }
};