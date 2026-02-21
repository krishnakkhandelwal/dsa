class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> xorprefix(n);
        
        xorprefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            xorprefix[i] = xorprefix[i-1] ^ arr[i];
        }

        vector<int> out(queries.size());
        
        for(int i = 0; i < queries.size(); i++){
            int L = queries[i][0];
            int R = queries[i][1];
            
            if(L == 0)
                out[i] = xorprefix[R];
            else
                out[i] = xorprefix[R] ^ xorprefix[L-1];
        }
        
        return out;
    }
};