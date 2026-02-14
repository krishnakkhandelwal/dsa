//https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1


class Solution {
  public:
    int search(string &pat, string &txt) {
        
        int k = pat.size();
        int n = txt.size();
        
        if(k > n) return 0;
        
        vector<int> freq(26,0), freqw(26,0);
        

        for(char c : pat)
            freq[c - 'a']++;
        

        for(int i=0; i<k; i++)
            freqw[txt[i] - 'a']++;
        
        int ans = 0;
        if(freq == freqw) ans++;
        
        for(int i=k; i<n; i++){
            freqw[txt[i] - 'a']++;     
            freqw[txt[i-k] - 'a']--;   
            
            if(freq == freqw) ans++;
        }
        
        return ans;
    }
};

