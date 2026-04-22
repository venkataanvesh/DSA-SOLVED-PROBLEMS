class Solution {
private:
    vector<pair<int, int>> range;
    
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    
    vector<int> manacher(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        return vector<int>(begin(res) + 1, end(res) - 1);
    }
    
    void dfs(int node, vector<int> tree[], string &s, string &res, int par = -1) {
        int idx = res.size();
        for (int child : tree[node]) {
            if (child == par) continue;
            dfs(child, tree, s, res, node);
        }
        
        res += s[node];
        range[node] = {idx, res.size() - 1};
    }

public:
    vector<bool> findAnswer(vector<int> &parent, string &s) {
        int n = parent.size();
        vector<int> tree[n];
        for (int i = 1; i < n; i++) tree[parent[i]].push_back(i);

        range.resize(n);
        string res;
        dfs(0, tree, s, res);

        vector<int> manacher_array = manacher(res);

        vector<bool> ans(n, false);
        
        for (int i = 0; i < n; i++) {
            auto &[a, b] = range[i];
            int len = b - a + 1;
            int temp = manacher_array[a + b] - 1;
            if (temp >= len) ans[i] = true;
        }

        return ans;
    }
};
