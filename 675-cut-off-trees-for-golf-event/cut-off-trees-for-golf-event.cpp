class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int bfs(vector<vector<int>>& f,int sr,int sc,int tr,int tc)
    {
        if(sr==tr and sc==tc) return 0;
        vector<vector<bool>> vis(f.size(),vector<bool>(f[0].size(),false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++)
            {
                auto [x,y] = q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int newX = x+dx[d];
                    int newY = y+dy[d];
                    if(newX>=0 and newX<f.size() and newY>=0 and newY<f[0].size() and f[newX][newY]!=0 and !vis[newX][newY])
                    {
                        if(newX == tr and newY == tc) return steps;
                        vis[newX][newY] = true;
                        q.push({newX,newY});
                    }
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<tuple<int,int,int>> v;
        for(int i=0;i<forest.size();i++)
        {
            for(int j=0;j<forest[0].size();j++)
            {
                if(forest[i][j]>1)
                {
                    v.emplace_back(forest[i][j],i,j);
                }
            }
        }

        sort(v.begin(),v.end());

        int tolStep = 0;
        int sr=0,sc=0;
        for(auto &[height,tr,tc]:v)
        {
            int s = bfs(forest,sr,sc,tr,tc);
            if(s==-1) return -1;
            tolStep +=s;
            sr = tr;
            sc = tc;
        }
        return tolStep;
    }
};