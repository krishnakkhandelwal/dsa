// tc - o(n logn)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> s;
        vector<int> result;

        for(int i=0;i<n;i++){
            s.insert(nums[i]);

            if (i >= k - 1) {
                result.push_back(*s.rbegin()); 
                s.erase(s.find(nums[i - k+1]));
            }        
        }
        return result;         
    }
};