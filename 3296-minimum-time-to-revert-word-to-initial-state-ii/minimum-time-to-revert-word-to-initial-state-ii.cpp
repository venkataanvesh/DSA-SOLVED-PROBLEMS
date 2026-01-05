class Solution {
    // calculate prefix matching 
    vector<int> z_fn(string &s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i > r) {
                l = r = i;
                while(r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }else {
                int cur = i - l;
                if(z[cur] + i < r + 1) z[i] = z[cur];
                else {
                    l = i;
                    while(r < n && s[r] == s[r - l]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
    
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size(), ans = INT_MAX;
        vector<int> z = z_fn(word);
        
        // calculate answer
        for(int i = 0; i < n; i += k) {
            if(z[i] == (n - i)) {
                ans = min(ans, i / k);
            }
        } 
        
        return ans == INT_MAX ? (n + k - 1) / k : ans;
    }
};