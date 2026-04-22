class Solution {
public:
    string mergeCharacters(string s, int k) 
    {
        // f stores the last seen index of each character in the UPDATED string
        vector<int> f(26, -1);
        int del_ct = 0; // Tracks how many characters have been merged/removed
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            int v = s[i] - 'a';
            // The current character's index in the "active" string
            int cur_idx = i - del_ct;

            if(f[v] == -1) 
            {
                // First time seeing this character
                f[v] = cur_idx; 
                ans += s[i];
            }
            else 
            {
                // Check if the distance to the last occurrence is <= k
                if(cur_idx - f[v] <= k) {
                    del_ct++; // Merge happens: increment deletion count
                }
                else
                {
                    // Distance > k: cannot merge, update last seen index
                    f[v] = cur_idx;
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};