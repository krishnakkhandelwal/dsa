// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        int maxi = sum;
        
        for(int i = 1; i <= n - k; i++){
            sum = sum - arr[i-1] + arr[i+k-1];
            maxi = max(maxi, sum);
        }
        
        
        return maxi;
    }
};
