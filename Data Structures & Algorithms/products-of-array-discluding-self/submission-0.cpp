class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        vector<int> prefix(nums.size()+1, 1);
        vector<int> suffix(nums.size()+1, 1);

        for(int i=1;i<prefix.size();i++){
            prefix[i]= prefix[i-1]*nums[i-1];
            // cout<<prefix[i+1]<<" ";
        }
        for(auto it : prefix) cout<<it<<" ";
        cout<<endl;
        for(int i=nums.size()-2;i>=0;i--){
            product*=nums[i+1];
            suffix[i]=product;
        }

        for(auto it : suffix) cout<<it<<" ";

        // for(auto it : nums) product*it;
        vector<int> out;
        for(int i=0;i<nums.size();i++){
            out.push_back(prefix[i]*suffix[i]);
        }
        // for(auto it: nums){
        //     out.push_back(product/it);
        // }

        // How to do this without the division operator then How?
        //presum and suffix sum approach may be ??
        //How will that look though 
        // 1  2  4  6
        // 1  1  2  8 48
        // 48 24 6  1  1
        // 0  1  2  3  4
        return out;
    }
};
