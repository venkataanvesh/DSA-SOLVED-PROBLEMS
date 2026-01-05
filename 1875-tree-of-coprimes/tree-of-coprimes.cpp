#include<algorithm>
class Solution {
public:

    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> b,a,d;
    int n;

    void dfs(int x,int p)
    {
       for(auto& c:adj[x])
       {
        if(c!=p)
        {
            d[c]=1+d[x];
            dfs(c,x);
        }
       }

    }

    void dfs2(int x,int p)
    {
        int dis=-1;
        int z=-1;
        for(int y=1;y<=50;y++)
        {
            if(b[y]!=-1)
            {
             if(__gcd(y,a[x])==1)
             {
                if(d[b[y]]>dis)
                {
                    z=b[y];
                    dis=d[b[y]];
                }
             }
            }
        }
        ans[x]=z;
        int store=b[a[x]];
        b[a[x]]=x;
        for(auto& c:adj[x])
        {
            if(c!=p)
            {
                dfs2(c,x);
            }
        }
        b[a[x]]=store;
    }
    vector<int> getCoprimes(vector<int>& a, vector<vector<int>>& edges) {
        
         this->a=a;
         this->n=a.size();
         this->ans.resize(n);
         this->adj.resize(n);
         this->b.resize(51,-1);
         this->d.resize(n,0);
         for(auto& x:edges)
         {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
         }
         dfs(0,-1);
         dfs2(0,-1);

         return ans;
    }
};