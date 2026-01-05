class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]++;
                ans++;
            }
        }
        return ans;
    }
};