//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int m = numbers.size() -1;
        int n=0;
        
        while(m>n){
            if(numbers[n]+numbers[m] > target){
                m--;
            }
            else if(numbers[n]+numbers[m]==target){
                    return {n + 1, m + 1};
                }
            else{
                n++;
            }
        }
        return {};
    }
};
