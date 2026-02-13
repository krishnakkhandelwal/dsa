# solution for https://www.geeksforgeeks.org/problems/difference-array/1


class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        
        //difference array contruction
        int n= arr.size();
        vector<int> diff(n);
        

        diff[0]=arr[0];
        for(int i=1;i<n;i++){
            diff[i]=arr[i]-arr[i-1];
        }
        int l, r;
        int m=opr.size();
        for(int i=0;i<m;i++){
            l=opr[i][0];
            r=opr[i][1];
            diff[l] += opr[i][2];
            diff[r+1] -= opr [i][2]; 
        }
        
        arr[0]=diff[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+diff[i];
        }
        return arr;
        
    }
};
