class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s = nums.size();
        int n = 1 << s;  
        
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            vector<int> subset;
            
            for(int j = 0; j < s; j++) {
                if(i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }            
            ans.push_back(subset);
        }        
        return ans;
    }
};