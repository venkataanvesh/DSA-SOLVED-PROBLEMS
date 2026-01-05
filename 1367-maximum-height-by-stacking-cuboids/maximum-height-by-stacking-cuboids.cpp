class Solution {
    int m;
    int dp[101][102];
private:
    int f(int curr, int prev, vector<vector<int>>& cub){
        if(curr == m) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int ans = 0;
        if(prev == -1) ans = max(f(curr+1,prev,cub), cub[curr][0]+f(curr+1,curr,cub));
        else{
            bool flag = true;
            for(int i=0; i<3; i++){
                if(cub[prev][i] < cub[curr][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans = max(f(curr+1,prev,cub), cub[curr][0]+f(curr+1,curr,cub));
            else ans = f(curr+1,prev,cub);
        }
        return dp[curr][prev+1] = ans;
    }
public:
    int maxHeight(vector<vector<int>>& cub) {
        m = cub.size();
        for(auto& it: cub)
            sort(it.begin(), it.end(), greater<int>());
        sort(cub.begin(), cub.end(), greater<vector<int>>());

        memset(dp, -1, sizeof(dp));
        return f(0,-1,cub);
    }
};